#include <iostream>
#include "queues.h"
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
using namespace std;

//Main functions
void checkneighbors(int col, int row);
int position(int width, int columns, int x);
int solvegame2();
void get_start_end_pos();
void gamereset();
void drawgame();


//Temporary functions
void creategameworld();
void printgame();
void printbool();
int solvegame();

#define WINDOWWIDTH 1000
#define WINDOWHEIGHT 800

#define COL 6
#define ROW 6


//queue in x and y posisjon
myqueue qcol;
myqueue qrow;

//startpos and endpos of the game
int startposx;
int startposy;


int move_count = 0;
int nodes_left = 1;
int nodes_next = 0;
bool mouse = false;
bool enqueustart = false;


char game[ROW][COL] = {0};//gameworld
bool visitied[ROW][COL] = {false};//visited nodes


int worldSize = ROW * COL;
int recWidth = WINDOWWIDTH / COL;
int recHeight = WINDOWHEIGHT / ROW;
sf::RectangleShape rectangles[ROW*COL];
int mousefind_color = 0;

//* MAIN
int main(){

    creategameworld();
    drawgame();

    int posx;
    int posy;

    int startx;
    int starty;

    bool startingposition = false;
    bool finishposition = false;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Maze Game");
    // Start the game loop
    while (window.isOpen()) {

        if(mouse){
            cout << "steps to mouse: " << move_count << endl;
            sf::sleep(sf::milliseconds(2000));
            gamereset();
            startingposition = false;
            finishposition = false;
            creategameworld();
            drawgame();

        }

        //start Dijkstra's shortest path algorithm using breath first search
        if(startingposition == true && finishposition == true){
            if(enqueustart == false){
                get_start_end_pos();
                //add the startposition to each queue
                qcol = enqueue(qcol, startposx);
                qrow = enqueue(qrow, startposy);
                visitied[startposy][startposx] = true; //set startposition to true
                enqueustart = true;
            }
            int solvethegame = solvegame2();
            if(solvethegame == -1){
                cout << "Cant find the mouse" << endl;
                sf::sleep(sf::milliseconds(2000));
                gamereset();
                startingposition = false;
                finishposition = false;
                creategameworld();
                drawgame();
            }
        }


        // Event handler
        sf::Event event;

        while ((window.pollEvent(event))) {
            // check for events
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;


                    //Mouse button pressed
                case sf::Event::MouseButtonPressed:
                    switch (event.key.code)
                    {
                        case sf::Mouse::Left:
                            posx = position(recWidth, COL, sf::Mouse::getPosition(window).x);
                            posy = position(recHeight, ROW, sf::Mouse::getPosition(window).y);


                            if(startingposition == false && finishposition == false){
                                for (int i = 0; i < COL; ++i) {
                                    if(posx == recWidth*i){
                                        startx = i;
                                        break;
                                    }
                                }
                                for (int i = 0; i < COL; ++i) {
                                    if(posy == recHeight*i){
                                        starty = i;
                                        break;
                                    }
                                }


                                for (int i = 0; i < worldSize; ++i) {
                                    if (rectangles[i].getPosition() == sf::Vector2f(posx, posy) && rectangles[i].getFillColor() != sf::Color(250, 250, 250)) {
                                        rectangles[i].setFillColor(sf::Color(150, 250, 150));
                                        game[starty][startx] = 's';
                                        startingposition = true;
                                        break;

                                    }
                                }
                            }
                            else if(startingposition == true && finishposition == false){
                                for (int i = 0; i < COL; ++i) {
                                    if(posx == recWidth*i){
                                        startx = i;
                                        break;
                                    }
                                }
                                for (int i = 0; i < COL; ++i) {
                                    if(posy == recHeight*i){
                                        starty = i;
                                        break;
                                    }
                                }


                                for (int i = 0; i < worldSize; ++i) {
                                    if (rectangles[i].getPosition() == sf::Vector2f(posx, posy) && rectangles[i].getFillColor() == sf::Color(100, 100, 100)) {
                                        rectangles[i].setFillColor(sf::Color(150, 150, 150));
                                        game[starty][startx] = 'p';
                                        finishposition = true;
                                        break;

                                    }
                                }
                            }

                    }

                    break;

            }
        }


        // Clear screen
        window.clear();

        for (int i = 0; i < worldSize; ++i) {
            window.draw(rectangles[i]);
        }

        // Update the window
        window.display();
        sf::sleep(sf::milliseconds(100));

    }

    return 0;
}
//* MAIN


void drawgame(){
    int x = 0;
    int y = 0;
    int n = 0;
    for (int i = 0; i < ROW; ++i) {
        for(int j=0; j<COL; j++){

            sf::RectangleShape rectangle(sf::Vector2f(recWidth, recHeight));
            rectangle.setPosition(x, y);


            if (game[i][j] == 'w') {
                rectangle.setFillColor(sf::Color(100, 100, 100));
            }
            else if(game[i][j] == 'z') {
                rectangle.setFillColor(sf::Color(250, 250, 250));
            }

            rectangle.setOutlineThickness(1.f);
            rectangle.setOutlineColor(sf::Color(0, 0, 0));

            rectangles[n] = rectangle;
            x = x + recWidth;
            n++;
        }
        x = 0;
        y = y + recHeight;
    }
}


void gamereset(){
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            game[i][j] = 0;
            visitied[i][j] = false;
        }
    }

    mousefind_color = 0;
    move_count = 0;
    nodes_left = 1;
    nodes_next = 0;
    mouse = false;
    enqueustart = false;
    qcol.front = -1;
    qcol.rear = -1;
    qrow.front = -1;
    qrow.rear = -1;

}


int solvegame2(){

    //loops true each cell until we find the mouse or not.
    if (qcol.rear != -1){
        int col = qcol.q[qcol.front];
        int row = qrow.q[qrow.front];
        if(game[row][col] == 'p'){
            mouse = true;
            cout << "Mouse Found!" << endl;
            return 0;
        }
        qcol = dequeue(qcol);
        qrow = dequeue(qrow);

        checkneighbors(col, row);

        //If the neighbornodes has been checked, increase move_count
        nodes_left--;
        if(nodes_left == 0){
            nodes_left = nodes_next;
            nodes_next = 0;
            move_count++;
            if(mousefind_color == 250)
                mousefind_color = 0;
            else
                mousefind_color += 25;

        }
    }
    else{
        return -1;
    }

}




//checks all the neighborcells
void checkneighbors(int col, int row){
    int posxgame;
    int posygame;

    //direction vektorer
    int dc[] = {0, 0, 1, -1};
    int dr[] = {-1, 1, 0, 0};


    for (int i = 0; i < 4; ++i) {
        int coltemp = col + dc[i];
        int rowtemp = row + dr[i];

        if(coltemp >= 0 && rowtemp >= 0 && coltemp <= COL - 1 && rowtemp <= ROW - 1){
            if(visitied[rowtemp][coltemp] == false && game[rowtemp][coltemp] != 's' && game[rowtemp][coltemp] != 'z'){
                qcol = enqueue(qcol, coltemp);
                qrow = enqueue(qrow, rowtemp);
                if(game[rowtemp][coltemp] != 'p'){
                    game[rowtemp][coltemp] = 'X';
                    posxgame = recWidth * coltemp;
                    posygame = recHeight * rowtemp;

                    for (int j = 0; j < worldSize; ++j) {
                        if (rectangles[j].getPosition() == sf::Vector2f(posxgame, posygame)){
                            rectangles[j].setFillColor(sf::Color(mousefind_color, 0, 0));
                        }
                    }
                }
                visitied[rowtemp][coltemp] = true;
                nodes_next++;
            }
        }

    }
}



void get_start_end_pos(){

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if(game[i][j] == 's'){
                startposx = j;
                startposy = i;
            }
        }
    }
}





//Prints out the 2 dimentional game to the terminal
void printgame(){

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            cout << game[i][j];

        }
        cout << "\n";

    }

    cout << "\n\n\n";

}




void creategameworld(){
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
         if(i == 4) {
                game[i][j] = 'z';
            }
         else
             game[i][j] = 'w';

        }
    }
}

void creategameworld2(){
    string file = "mazeworld.txt";
    ifstream inFile;
    inFile.open(file);

    string line = "";
    string temp = "";

    if(inFile.is_open())
    {
        int k = 0;
        int j = 0;

        while(getline(inFile, line)){
            if(line != ""){
                j = 0;
                line = line + ',';

            }
        }
    }



}



int position(int width, int columns, int x){
    int first = 0;
    int last = width;

    for (int i = 0; i < columns; ++i) {
        if(x > first && x < last)
        {
            x = width * i;
            return x;
        }
        first = last;
        last = last + width;

    }

}
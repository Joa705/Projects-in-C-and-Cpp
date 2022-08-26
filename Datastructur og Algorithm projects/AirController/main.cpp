#include <iostream>
#include <SFML/Graphics.hpp>
#include "flightqueue.h"

//Assume Radius: WINDOWHEIGHT/2 - 50 = 150 km
// Distance = Velocity * time

#define WINDOWWIDTH 600
#define WINDOWHEIGHT 600

struct Flight{
    int velocity;
    int pos[2];
};


//Functions
sf::CircleShape DrawSurveillanceArea(int radius);
double randomnumbers(double min, double max);
void GenerateFlight(struct Flight *f, int i);




struct Flight flights[100];
Flightqueue myqueue;


int main() {

    srand(time(nullptr));


    sf::CircleShape outCircle = DrawSurveillanceArea(WINDOWHEIGHT/2 - 50);
    sf::CircleShape midCircle = DrawSurveillanceArea(WINDOWHEIGHT/2 - 80);
    sf::CircleShape midinnerCircle = DrawSurveillanceArea(WINDOWHEIGHT/2 - 140);
    sf::CircleShape innerCircle = DrawSurveillanceArea(WINDOWHEIGHT/2 - 230);



    sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "Air Controler");
    while (window.isOpen()) {


        // Event handler
        sf::Event event;
        while ((window.pollEvent(event))) {
            switch (event.type) {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;
            }

        }

        // Clear screen
        window.clear();


        //Draw updated window
        window.draw(outCircle);
        window.draw(midCircle);
        window.draw(midinnerCircle);
        window.draw(innerCircle);


        // Update the window
        window.display();
        sf::sleep(sf::milliseconds(100));

    }

    return 0;
}



sf::CircleShape DrawSurveillanceArea(int radius){
    sf::CircleShape Circle;
    Circle.setRadius(radius);
    Circle.setOutlineThickness(1);
    Circle.setPointCount(1000);
    Circle.setFillColor(sf::Color::Black);
    Circle.setPosition(WINDOWWIDTH/2 - radius, WINDOWHEIGHT/2 - radius);

    return Circle;
}


void GenerateFlight(struct Flight *f, int i){
    f[i].velocity = randomnumbers(500, 1000);

}



// Function that returns a random number between min and max.
double randomnumbers(double min, double max){
    return ((double)rand()/RAND_MAX)*(max-min)+min;
}

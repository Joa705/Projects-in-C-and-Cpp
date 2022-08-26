#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "stack.h"
#include "list.h"
using namespace std;


//Functions
float line_function_x(float x);
float line_function_y(float y);



int main()
{

    //Game line Horizontal
    sf::VertexArray line_Horizontal(sf::Lines, 10);
    int z = 0;
    int yline = 100;
    for (int i = 0; i <= 9; ++i) {
        if (z == 0)
        {
            line_Horizontal[i].position = sf::Vector2f (0, yline);
            z++;
        }else
        {
            line_Horizontal[i].position = sf::Vector2f (800, yline);
            z = 0;
            yline += 100;
        }
    }


    // Game line vertical
    sf::VertexArray line_Vertical(sf::Lines, 14);
    int q = 0;
    int xline = 100;
    for (int i = 0; i <= 13; ++i) {
        if (q == 0)
        {
            line_Vertical[i].position = sf::Vector2f (xline, 0);
            q++;
        }else
        {
            line_Vertical[i].position = sf::Vector2f (xline, 600);
            q = 0;
            xline += 100;
        }
    }


    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Polygon Game");

    //If game finished, clear current mouse movement
    int finished = false;

    // Checks if a node is poped, then makes posx and posy to prev position
    int remove = true;

    //Previous Position, to match the current line movement
    int posx;
    int posy;

    //Current mouse movement line
    int x;
    int y;

    int lastposx;
    int lastposy;

    //Head Node
    stack *testStack = CreateHead();
    nodeList *NodeList = CreateNewNodeList();

    //Count total lines
    int line_count = 0;


    // Start the game loop
    while (window.isOpen())
    {
        /*int i = -1;
        sf::ConvexShape main_line;
        main_line.setPointCount(line_count);
        for(stack* current = testStack->next; current != nullptr; current = current->next)
        {
            i++;

                main_line.setPoint(i,sf::Vector2f(current->values[0], current->values[1]));
                main_line.setOutlineThickness(2);
                main_line.setOutlineColor(sf::Color::Red);
                main_line.setFillColor(sf::Color::Black);

        }*/


        int i = 0;
        sf::VertexArray main_line(sf::Lines, line_count);
        for(stack* current = testStack->next; current != nullptr; current = current->next)
        {
            //Get the prev position for the line, when poping a element from the stack
            if(i == 0)
            {
                if(remove == false)
                {
                    posx = current->values[0];
                    posy = current->values[1];
                }
            }

            //Start position to when we are ending the game
            lastposx = current->values[0];
            lastposy = current->values[1];

            if(i % 2 == 1)
            {
                main_line[i].position = sf::Vector2f(current->values[0], current->values[1]);
                main_line[i].color = sf::Color::Green;
                i++;
                main_line[i].position = sf::Vector2f(current->values[0], current->values[1]);
                main_line[i].color = sf::Color::Green;
                i++;
            } else
            {

                main_line[i].position = sf::Vector2f(current->values[0], current->values[1]);
                main_line[i].color = sf::Color::Green;
                i++;
            }


        }


        //Vertex for the moveable line
        sf::Vertex current_line[] =
                {
                        sf::Vertex(sf::Vector2f(posx, posy)),
                        sf::Vertex(sf::Vector2f(x, y))
                };




        // Event handler
        sf::Event event;

        while ((window.pollEvent(event)))
        {
            // check for events
            switch (event.type)
            {
                // window closed
                case sf::Event::Closed:
                    window.close();
                    break;



                    //Mouse button pressed
                case sf::Event::MouseButtonPressed:
                    switch (event.key.code)
                    {
                        case sf::Mouse::Left:
                            cout << "left button pressed" << endl;
                            remove = true;
                            if(line_count == 0)
                            {
                                line_count += 1;
                            }
                            else
                            {
                                line_count += 2;
                            }



                            // Get current mouse positions
                            posx = line_function_x(sf::Mouse::getPosition(window).x);
                            posy = line_function_y(sf::Mouse::getPosition(window).y);

                            //Push new node and print the linked list
                            PushNodePtr(posx, posy, testStack);
                            PrintLinkedList(testStack);

                            finished = false;
                            break;


                        case sf::Mouse::Right:
                            cout << "right button pressed" << endl;
                            if(PopNodePtr(testStack))
                            {
                                PrintLinkedList(testStack);
                                remove = false;
                                if(line_count == 1)
                                {
                                    line_count = 0;
                                }
                                else
                                {
                                    line_count -= 2;

                                }
                            }

                            break;


                        case::sf::Mouse::Middle:
                            cout << "Middle button pressed" << endl;

                            if (finished) {
                                PushNodeList(*testStack, NodeList);
                                PrintNodeList(NodeList);
                                testStack = CreateHead();
                                line_count = 0;
                            } else {
                                line_count += 2;
                                finished = true;
                                PushNodePtr(lastposx, lastposy, testStack);
                                PrintLinkedList(testStack);
                            }

                            break;
                    }

                    //When moving the mouse
                case sf::Event::MouseMoved:

                    if(line_count >= 1)
                    {
                        // Get current mouse movement
                        x = event.mouseMove.x;
                        y = event.mouseMove.y;
                    }

                    break;
            }


        }



        // Clear screen
        window.clear();

        //Draw game lines on screen
        window.draw(line_Horizontal);
        window.draw(line_Vertical);

        //Draw polygon
        window.draw(main_line);


        if(line_count >= 1 && !finished)
        {
            window.draw(current_line, 2, sf::Lines);

        }



        // Update the window
        window.display();
        sf::sleep(sf::milliseconds(50));

    }



    std::cout << "Program End\n\n" << endl;

    for (nodeList* i = NodeList; i != nullptr; i = i->next) {
        if (i->next == nullptr) {
            std::cout << "Node: " << i << ": ";
            for (stack* j = i->polygon.next; j != nullptr; j = j->next) {
                if (j->next == nullptr) {
                    printf("(%d, %d)\n", j->values[0], j->values[1]);
                } else {
                    printf("(%d, %d) -> ", j->values[0], j->values[1]);
                }
            }
            cout << endl;
        } else {
            std::cout << "Node: " << i << ": ";
            for (stack* j = i->polygon.next; j != nullptr; j = j->next) {
                if (j->next == nullptr) {
                    printf("(%d, %d)\n", j->values[0], j->values[1]);
                } else {
                    printf("(%d, %d) -> ", j->values[0], j->values[1]);
                }
            }
            cout << endl;
        }

    }


    return 0;
}





// X Positon line
float line_function_x(float x)
{
    float xval = 0;

    for (int i = 100; i <= 800; i+=100) {
        if(x > xval && x <= (float)i)
        {
            x = (float)i - 50;

        }
        xval += 100;
    }

    return x;


}
// Y Position line
float line_function_y(float y)
{
    float yval = 0;

    for (int j = 100; j < 700; j+=100) {
        if(y > yval && y <= (float)j)
        {
            y = (float)j - 50;
        }
        yval += 100;

    }
    return y;
}


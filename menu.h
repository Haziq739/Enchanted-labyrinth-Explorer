
#include "game.h"
#include"Help.h"
#include"Maze.h"
#define Max_Menu 4
using namespace sf;


class Menu
{
private:
    int menuSelected;
    Font font;
    Text menuOption[Max_Menu];

public:
    //add menu attributes here
    Menu()
    {

    }
    Menu(float width, float height)
    {
        sf::Color customColor(255, 255, 55, 200);
        sf::Color customColor2(255, 255, 255, 200);
        font.loadFromFile("C:\\Users\\munee\\OneDrive\\Desktop\\Semester 4\\Data Structures\\Project1\\Graphics\\arcade_6896660\\ARCADE_I.ttf");
        //constructors body
        menuOption[0].setFont(font);
        menuOption[0].setFillColor(customColor);
        menuOption[0].setString("Start New Game");
        menuOption[0].setCharacterSize(20);
        menuOption[0].setPosition(60.f, 220.f);

        menuOption[1].setFont(font);
        menuOption[1].setFillColor(customColor2);
        menuOption[1].setString("High Scores");
        menuOption[1].setCharacterSize(20);
        menuOption[1].setPosition(60.f, 275.f);

        menuOption[2].setFont(font);
        menuOption[2].setFillColor(customColor2);
        menuOption[2].setString("Help");
        menuOption[2].setCharacterSize(20);
        menuOption[2].setPosition(60.f, 330.f);

        menuOption[3].setFont(font);
        menuOption[3].setFillColor(customColor2);
        menuOption[3].setString("Quit");
        menuOption[3].setCharacterSize(20);
        menuOption[3].setPosition(60.f, 385.f);

        menuSelected = 0;
    }
    void draw(RenderWindow& window)
    {
        for (int i = 0; i < Max_Menu; i++)
        {
            window.draw(menuOption[i]);
        }
    }
    void moveUp()
    {
        sf::Color custom(255, 255, 255, 200);
        sf::Color custom2(255, 255, 55, 200);
        if (menuSelected > 0)
        {
            menuOption[menuSelected].setFillColor(custom);
            menuSelected--;
            menuOption[menuSelected].setFillColor(custom2);
        }
        else
        {
            menuOption[menuSelected].setFillColor(custom);
            menuSelected = Max_Help - 1;
            menuOption[menuSelected].setFillColor(custom2);
        }
    }

    void moveDown()
    {
        sf::Color customs(255, 255, 255, 200);

        sf::Color customs2(255, 255, 55, 200);
        if (menuSelected < Max_Help - 1)
        {
            menuOption[menuSelected].setFillColor(customs);
            menuSelected++;
            menuOption[menuSelected].setFillColor(customs2);
        }
        else
        {
            menuOption[menuSelected].setFillColor(customs);
            menuSelected = 0;
            menuOption[menuSelected].setFillColor(customs2);
        }
    }

    int getMenu_selected()
    {
        return menuSelected;
    }


    void display_menu()
    {


        Sprite MPng;    // Help sprite
        Texture M_texture;

        M_texture.loadFromFile("Graphics/Purple Neon Illustration Game Mode Mouse Pad (2).png");
        MPng.setTexture(M_texture);
        MPng.setScale(0.3, 0.404);


        SoundBuffer buffer;
        buffer.loadFromFile("Graphics/Audio/Menu Selection Click.wav");

        Sound sound;
        sound.setBuffer(buffer);

        SoundBuffer enter;
        enter.loadFromFile("Graphics/Audio/click.wav");

        Sound click;
        click.setBuffer(enter);

        // RenderWindow welWin;
         //Game g;
         //display menu screen here
         // add functionality of all the menu options here

        RenderWindow window(VideoMode(600, 600), "sfml_menu");
        Menu m(600.f, 600.f);
        while (window.isOpen())
        {
            //mouse position
          //  cout << "Mouse pos: " << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;


            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
                if (event.key.code == Keyboard::Escape)
                    window.close();
                if (event.type == Event::KeyReleased)
                {
                    if (event.key.code == Keyboard::Up)
                    {
                        sound.play();
                        m.moveUp();
                        break;
                    }
                    if (event.key.code == Keyboard::Down)
                    {
                        sound.play();
                        m.moveDown();
                        break;
                    }
                    if (event.key.code == Keyboard::Enter)
                    {
                        click.play();
                        if (m.getMenu_selected() == 0)
                        {
                            Maze m1;
                            m1.Draw();

                            /*  const int windowWidth = 1200;
                              const int windowHeight = 650;

                              sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Maze");
                              const int cellSize = 25;
                              const int mazeWidth = windowWidth / cellSize;
                              const int mazeHeight = windowHeight / cellSize;

                              Maze maze(mazeWidth, mazeHeight);
                              maze.generate();

                              const int mazeX = (windowWidth - mazeWidth * cellSize) / 2;
                              const int mazeY = (windowHeight - mazeHeight * cellSize) / 2;

                              maze.display(window, cellSize, mazeX, mazeY);*/


                              /*const int width = 10;
                                  const int height = 10;
                                  const int cellSize = 30;

                                  Maze maze(width, height);
                                  maze.generate();

                                  sf::RenderWindow window(sf::VideoMode(width * cellSize, height * cellSize), "Maze");

                                  while (window.isOpen()) {
                                      sf::Event event;
                                      while (window.pollEvent(event)) {
                                          if (event.type == sf::Event::Closed)
                                              window.close();
                                      }

                                      window.clear();

                                      maze.display(window, cellSize);

                                      window.display();
                                  }
                              */

                        }
                        if (m.getMenu_selected() == 1)
                        {
                            //highscores
                            int highscores[5];
                            string players[5];

                            fstream inputf("highscores.txt", ios::in);

                            for (int i = 0; i < 5; i++)
                            {
                                getline(inputf, players[i], ':');
                                inputf >> highscores[i];
                                inputf.ignore();
                            }

                            inputf.close();

                            RenderWindow highScoresWindow(VideoMode(500, 300), "High Scores");
                            Font highScoresFont;
                            highScoresFont.loadFromFile("img/ountry.ttf");

                            Text highScoresText;
                            highScoresText.setFont(highScoresFont);
                            highScoresText.setCharacterSize(20);
                            highScoresText.setPosition(50.f, 50.f);
                            string highScoresString;
                            for (int i = 0; i < 5; i++)
                            {
                                highScoresString += players[i] + ": " + to_string(highscores[i]) + "\n";
                            }

                            highScoresText.setString(highScoresString);
                            //window for diaplaying highscores
                            while (highScoresWindow.isOpen())
                            {
                                Event hsEvent;
                                while (highScoresWindow.pollEvent(hsEvent))
                                {
                                    if (hsEvent.type == Event::Closed)
                                        highScoresWindow.close();
                                    if (hsEvent.type == Event::KeyReleased)
                                    {
                                        if (hsEvent.key.code == Keyboard::Escape)
                                            highScoresWindow.close();
                                    }
                                }

                                highScoresWindow.clear();
                                highScoresWindow.draw(highScoresText);
                                highScoresWindow.display();
                            }
                        }
                        if (m.getMenu_selected() == 2)
                        {
                            //help menu
                            Help help;
                            help.display_help();
                        }
                        if (m.getMenu_selected() == 3)
                            window.close(); //quit
                        break;
                    }
                }

            }
            window.clear();
            window.draw(MPng);
            m.draw(window);
            window.display();
        }



    }

    ~Menu() {};
};

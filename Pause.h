#pragma once
#include"game.h"
#define Max_Pause 2
class Pause
{
private:
    int select;
    Font font;
    Text pause[Max_Pause];
public:
    Pause() {}
    Pause(float width, float height)
    {
        sf::Color customColor(255, 255, 255, 200);
        sf::Color customColor2(204, 153, 255, 200);
        font.loadFromFile("C:\\Users\\munee\\OneDrive\\Desktop\\Semester 4\\Data Structures\\Project1\\Graphics\\arcade_6896660\\ARCADE_I.ttf");
        //constructors body
        pause[0].setFont(font);
        pause[0].setFillColor(customColor);
        pause[0].setString("Resume");
        pause[0].setCharacterSize(40);
        pause[0].setPosition(520.f, 190.f);

        pause[1].setFont(font);
        pause[1].setFillColor(customColor2);
        pause[1].setString("Quit");
        pause[1].setCharacterSize(40);
        pause[1].setPosition(550.f, 270.f);

        select = 0;
    }
    void draw(RenderWindow& window)
    {
        for (int i = 0; i < Max_Pause; i++)
        {
            window.draw(pause[i]);
        }
    }
    void moveUp()
    {
        sf::Color custom(255, 255, 255, 200);
        sf::Color custom2(204, 153, 255, 200);
        if (select > 0)
        {
            pause[select].setFillColor(custom2);
            select--;
            pause[select].setFillColor(custom);
        }
        else
        {
            pause[select].setFillColor(custom2);
            select = Max_Pause - 1;
            pause[select].setFillColor(custom);
        }
    }

    void moveDown()
    {
        sf::Color customs(255, 255, 255, 200);

        sf::Color customs2(204, 153, 255, 200);
        if (select < Max_Pause - 1)
        {
            pause[select].setFillColor(customs2);
            select++;
            pause[select].setFillColor(customs);
        }
        else
        {
            pause[select].setFillColor(customs2);
            select = 0;
            pause[select].setFillColor(customs);
        }
    }

    int getMenu_selected()
    {
        return select;
    }

    void display_Pause(int& s)
    {

        SoundBuffer buffer;
        SoundBuffer enter;

        buffer.loadFromFile("Graphics/Audio/Menu Selection Click.wav");
        enter.loadFromFile("Graphics/Audio/click.wav");

        sf::Sound sound;
        sound.setBuffer(buffer);
        sound.setVolume(30);

        Sound click;
        click.setBuffer(enter);

        click.setVolume(100);

        Sprite PausePng;    // Pause sprite
        Texture Pause_texture;

        Pause_texture.loadFromFile("Graphics/2(1).png");
        PausePng.setTexture(Pause_texture);
        PausePng.setScale(0.66, 0.6);

        RenderWindow window(VideoMode(1200, 650), "Pause");
        Pause m(1000.f, 600.f);
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
                {
                    window.close();
                }
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
                            window.close();
                        }
                        else if (m.getMenu_selected() == 1)
                        {
                            s = 1;
                            window.close();
                        }

                    }
                }
            }
            window.clear();
            window.draw(PausePng);
            m.draw(window);
            window.display();
        }



    }
    ~Pause() {}



};
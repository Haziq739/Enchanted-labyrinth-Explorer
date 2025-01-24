#pragma once
#define Max_Help 4

using namespace sf;

class Help
{
private:
    int select;
    Font font;
    Text help[Max_Help];
public:
    Help() {}
    Help(float width, float height)
    {
        sf::Color customColor(255, 255, 255, 200);
        sf::Color customColor2(204, 153, 255, 200);
        font.loadFromFile("C:\\Users\\munee\\OneDrive\\Desktop\\Semester 4\\Data Structures\\Project1\\Graphics\\arcade_6896660\\ARCADE_I.ttf");
        //constructors body
        help[0].setFont(font);
        help[0].setFillColor(customColor2);
        help[0].setString("Back");
        help[0].setCharacterSize(20);
        help[0].setPosition(300.f, 180.f);

        help[1].setFont(font);
        help[1].setFillColor(customColor);
        help[1].setString("Controls");
        help[1].setCharacterSize(20);
        help[1].setPosition(300.f, 240.f);

        help[2].setFont(font);
        help[2].setFillColor(customColor);
        help[2].setString("Game Rules");
        help[2].setCharacterSize(20);
        help[2].setPosition(300.f, 300.f);

        help[3].setFont(font);
        help[3].setFillColor(customColor);
        help[3].setString("About");
        help[3].setCharacterSize(20);
        help[3].setPosition(300.f, 360.f);

        select = 0;
    }
    void draw(RenderWindow& window)
    {
        for (int i = 0; i < Max_Help; i++)
        {
            window.draw(help[i]);
        }
    }
    void moveUp()
    {
        sf::Color custom(255, 255, 255, 200);
        sf::Color custom2(204, 153, 255, 200);
        if (select > 0)
        {
            help[select].setFillColor(custom);
            select--;
            help[select].setFillColor(custom2);
        }
        else
        {
            help[select].setFillColor(custom);
            select = Max_Help - 1;
            help[select].setFillColor(custom2);
        }
    }

    void moveDown()
    {
        sf::Color customs(255, 255, 255, 200);

        sf::Color customs2(204, 153, 255, 200);
        if (select < Max_Help - 1)
        {
            help[select].setFillColor(customs);
            select++;
            help[select].setFillColor(customs2);
        }
        else
        {
            help[select].setFillColor(customs);
            select = 0;
            help[select].setFillColor(customs2);
        }
    }

    int getMenu_selected()
    {
        return select;
    }

    void display_help()
    {
        Sprite helpPng;    // Help sprite
        Texture help_texture;

        SoundBuffer buffer;
        buffer.loadFromFile("Graphics/Audio/Menu Selection Click.wav");

        Sound sound;
        sound.setBuffer(buffer);

        SoundBuffer enter;
        enter.loadFromFile("Graphics/Audio/click.wav");

        Sound click;
        click.setBuffer(enter);

        help_texture.loadFromFile("Graphics/4.png");
        helpPng.setTexture(help_texture);
        helpPng.setScale(0.354, 0.6);

        RenderWindow window(VideoMode(600, 600), "Help");
        Help m(600.f, 600.f);
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
                            window.close();
                        }
                        else if (m.getMenu_selected() == 1)
                        {
                            //controls
                        }
                        else if (m.getMenu_selected() == 2)
                        {
                            Sprite R;
                            Texture R_t;
                            R_t.loadFromFile("Graphics/5.png");
                            R.setTexture(R_t);
                            R.setScale(0.555, 0.559);
                            RenderWindow rules(VideoMode(1000, 600), "Game Rules");
                            while (rules.isOpen())
                            {
                                Event r;
                                while (rules.pollEvent(r))
                                {
                                    if (r.type == Event::Closed)
                                        rules.close();
                                    if (r.key.code == Keyboard::Escape)
                                        rules.close();
                                    if (r.type == Event::KeyReleased)
                                    {
                                        if (r.key.code == Keyboard::Enter)
                                        {
                                            rules.close();
                                        }
                                    }

                                }
                                rules.clear();
                                rules.draw(R);
                                rules.display();

                            }
                        }
                        else if (m.getMenu_selected() == 3)
                        {
                            Sprite A;
                            Texture A_t;
                            A_t.loadFromFile("Graphics/3.png");
                            A.setTexture(A_t);
                            A.setScale(0.535, 0.559);
                            RenderWindow about(VideoMode(1000, 600), "About");
                            while (about.isOpen())
                            {
                                Event a;
                                while (about.pollEvent(a))
                                {
                                    if (a.type == Event::Closed)
                                        about.close();
                                    if (a.key.code == Keyboard::Escape)
                                        about.close();
                                    if (a.type == Event::KeyReleased)
                                    {
                                        if (a.key.code == Keyboard::Enter)
                                        {
                                            about.close();
                                        }
                                    }

                                }
                                about.clear();
                                about.draw(A);
                                about.display();

                            }
                        }
                    }
                }
            }
            window.clear();
            window.draw(helpPng);
            m.draw(window);
            window.display();
        }



    }
    ~Help() {}

};
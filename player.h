#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

class Player {

public:
    int x, y;
    Sprite sprite;
    Texture texture;
    Player(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;

        texture.loadFromFile("Graphics/Sprites/player.png");
        sprite.setTexture(texture);
        sprite.setPosition(x, y); 
        sprite.setScale(1.5f, 1.5f);

    }

    void moveUp()
    {
        sprite.move(0, -10);
    }

    void moveDown()
    {
        sprite.move(0, +10);

    }

    void moveRight()
    {
        sprite.move(+10, 0);
    }

    void moveLeft()
    {
        sprite.move(-10, 0);
    }

    void drawPlayer(RenderWindow& window)   // Function for drwaing player
    {
        window.draw(sprite);
    }

    int getX()
    {
        return sprite.getPosition().x;    // getting x coordinate or x-position of player
    }

    int getY()
    {
        return sprite.getPosition().y;    // getting y coordinate or y-position of player
    }


};

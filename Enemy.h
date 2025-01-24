#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

class Enemy{

public:
    int x, y;
    Sprite sprite;
    Texture texture;
    Enemy(int xPos, int yPos, string path, float scaleX, float scaleY)
    {
        x = xPos;
        y = yPos;

        texture.loadFromFile(path);
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        sprite.setScale(scaleX, scaleY);

    }

    void moveUp()
    {
        sprite.move(0, -1);
    }

    void moveDown()
    {
        sprite.move(0, 1);

    }

    void moveRight()
    {
        sprite.move(1, 0);
    }

    void moveLeft()
    {
        sprite.move(-1, 0);
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

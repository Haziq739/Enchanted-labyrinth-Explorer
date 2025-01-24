#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

class Item {

public:
    int x, y;
    int key;
    Sprite sprite;
    Texture texture;
    Item(int xPos, int yPos, string s, float s1, float s2, int k)
    {
        x = xPos;
        y = yPos;

        texture.loadFromFile(s);
        sprite.setTexture(texture);
        sprite.setPosition(x, y);
        sprite.setScale(s1, s2);

        key = k;

    }

    void drawItem(RenderWindow& window)   // Function for drwaing player
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

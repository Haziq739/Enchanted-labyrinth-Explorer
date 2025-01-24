#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class Cell {

public:

    bool visited;
    Cell* N;
    Cell* S;
    Cell* E;
    Cell* W;

    bool wN, wS, wE, wW;
    int x, y;
    bool line;

    Cell() {

        visited = false;
        N = NULL;
        S = NULL;
        E = NULL;
        W = NULL;

        wN = true;
        wS = true;
        wE = true;
        wW = true;
        x = 0;
        y = 0;

        line = false;

    }

};


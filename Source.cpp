//#include <iostream>
//#include "Cells.h"
//#include "Stack.h"
//#include "player.h"
//#include <SFML/Graphics.hpp>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//using namespace sf;
//
//RectangleShape makeWalls(int x, int y, char a) {
//
//    RectangleShape wall;
//
//    int l = 60, w = 3;
//
//        if (a == 'n') {
//        
//            wall.setPosition(x, y - l);
//            wall.setFillColor(Color::Black);
//            wall.setSize(Vector2f(l, w));
//        
//        }
//        
//
//        if (a == 's') {
//        
//            wall.setPosition(x, y);
//            wall.setFillColor(Color::Black);
//            wall.setSize(Vector2f(l, w));
//        
//        }
//       
//
//        if (a == 'e') {
//        
//            wall.setPosition(x + l, y - l);
//            wall.setFillColor(Color::Black);
//            wall.setSize(Vector2f(w, l));
//        
//        }
//        
//
//        if (a == 'w') {
//        
//            wall.setPosition(x, y - l);
//            wall.setFillColor(Color::Black);
//            wall.setSize(Vector2f(w, l));
//        
//        }
//       
//        return wall;
//}
//
//int main()
//{
//    RenderWindow window(VideoMode(1300, 750), "Enchanted Labyrinth Explorer");
//    
//    const int X = 8, Y = 15;
//
//    Cell cells[X][Y];
//    Cell* c[X][Y];
//
//    for (int i = 0; i < X; i++) {
//
//        for (int j = 0; j < Y; j++) {
//
//            c[i][j] = &cells[i][j];
//
//        }
//
//    }
//
//    for (int i = 0; i < X; i++) {
//
//        for (int j = 0; j < Y; j++) {
//
//            c[i][j]->x = 90 + j * 60;
//            c[i][j]->y = 250 + i * 60;
// 
//            if (j < Y - 1)
//                c[i][j]->E = c[i][j + 1];
//            
//            if (i > 0)
//                c[i][j]->N = c[i - 1][j];
//
//            if (i < X - 1)
//                c[i][j]->S = c[i + 1][j];
//
//            if (j > 0)
//                c[i][j]->W = c[i][j - 1];
//                
//        }
//
//    }
//    
//    Cell* start = c[0][0];
//    Cell* p = start;
//    c[0][0]->visited = true;
//
//    srand(time(nullptr));
//
//    int randDir = 0;
//
//    bool fin = false;
//    Stack<Cell*> cellStack;
//    cellStack.push(start);
//
//    c[7][14]->wN = false;
//    c[7][14]->N->wS = false;
//
//    c[7][14]->wW = false;
//    c[7][14]->W->wE = false;
//
//    c[6][14]->wS = false;  
//    c[6][14]->S->wN = false;
//
//    c[6][14]->wW = false;
//    c[6][14]->W->wE = false;
//
//    c[6][14]->wN = false;
//    c[6][14]->N->wS = false;
//
//    c[7][13]->wE = false;
//    c[7][13]->E->wW = false;
//
//    
//    c[6][13]->wS = false;
//    c[6][13]->S->wN = false;
//
//    c[6][13]->wW = false;
//    c[6][13]->W->wE = false;
//
//    c[6][13]->wN = false;
//    c[6][13]->N->wS = false;
//
//    c[6][13]->wE = false;
//    c[6][13]->E->wW = false;
//
//
//
//    while (!fin) {
//
//        ////
//
//        randDir = 0;
//
//        if ((p->N != NULL && p->N->visited == false) && (p->E != NULL && p->E->visited == false) && (p->S != NULL && p->S->visited == false) && (p->W != NULL && p->W->visited == false))
//            randDir = rand() % 4 + 1;
//
//        else if ((p->E != NULL && p->E->visited == false) && (p->S != NULL && p->S->visited == false) && (p->W != NULL && p->W->visited == false))
//            randDir = rand() % 3 + 2;
//
//        else if ((p->N != NULL && p->N->visited == false) && (p->S != NULL && p->S->visited == false) && (p->W != NULL && p->W->visited == false)) {
//
//            randDir = rand() % 3;
//
//            switch (randDir) {
//            case 0:
//                randDir = 1;
//                break;
//            case 1:
//                randDir = 3;
//                break;
//            case 2:
//                randDir = 4;
//                break;
//            }
//
//        }
//
//        else if ((p->N != NULL && p->N->visited == false) && (p->E != NULL && p->E->visited == false) && (p->W != NULL && p->W->visited == false)) {
//
//            randDir = rand() % 3;
//
//            switch (randDir) {
//            case 0:
//                randDir = 1;
//                break;
//            case 1:
//                randDir = 2;
//                break;
//            case 2:
//                randDir = 4;
//                break;
//            }
//
//        }
//        else if ((p->N != NULL && p->N->visited == false) && (p->E != NULL && p->E->visited == false) && (p->S != NULL && p->S->visited == false)) {
//
//            randDir = rand() % 3;
//            randDir += 1;
//
//        }
//
//        else if ((p->N != NULL && p->N->visited == false) && (p->E != NULL && p->E->visited == false)) {
//
//            randDir = rand() % 2;
//            randDir += 1;
//
//        }
//
//        else if ((p->N != NULL && p->N->visited == false) && (p->W != NULL && p->W->visited == false)) {
//
//            randDir = rand() % 2;
//
//            
//            switch (randDir) {
//            case 0:
//                randDir = 1;
//                break;
//            case 1:
//                randDir = 4;
//                break;
//
//            }
//
//           
//        }
//
//        else if ((p->N != NULL && p->N->visited == false) && (p->S != NULL && p->S->visited == false)) {
//
//            randDir = rand() % 2;
//
//            if (randDir == 0) {
//                randDir = 1; 
//            }
//            else {
//                randDir = 3; 
//            }
//
//        }
//
//        else if ((p->E != NULL && p->E->visited == false) && (p->S != NULL && p->S->visited == false)) {
//
//            randDir = rand() % 2;
//
//            if (randDir == 0) {
//                randDir = 2;
//            }
//            else {
//                randDir = 3;
//            }
//
//        }
//
//        else if ((p->E != NULL && p->E->visited == false) && (p->W != NULL && p->W->visited == false)) {
//
//            randDir = rand() % 2;
//
//            if (randDir == 0) {
//                randDir = 2;
//            }
//            else {
//                randDir = 4;
//            }
//
//        }
//
//        else if ((p->S != NULL && p->S->visited == false) && (p->W != NULL && p->W->visited == false)) {
//
//            randDir = rand() % 2;
//
//            if (randDir == 0) {
//                randDir = 3;
//            }
//            else {
//                randDir = 4;
//            }
//
//        }
//
//        else if (p->N != NULL && p->N->visited == false)
//            randDir == 1;
//
//        else if (p->E != NULL && p->E->visited == false)
//            randDir == 2;
//
//        else if (p->S != NULL && p->S->visited == false)
//            randDir == 3;
//
//        else if (p->W != NULL && p->W->visited == false)
//            randDir == 4;
//
//        ////
//
//        if (randDir == 0) {
//
//            cellStack.pop();
//            p = cellStack.peek();
//
//            if (p == start) {
//
//                fin = true;
//
//            }
//                
//        }
//
//        else if (randDir == 1) {
//               
//            p->N->visited = true;
//            p->wN = false;
//            p = p->N;
//            p->wS = false;
//            cellStack.push(p);                  
//           
//        }
//        else if (randDir == 2) {             
//
//            p->E->visited = true;
//            p->wE = false;
//            p = p->E;
//            p->wW = false;
//            cellStack.push(p);
//                                    
//        }
//
//        else if (randDir == 3) {
//               
//            p->S->visited = true;
//            p->wS = false;
//            p = p->S;
//            p->wN = false;
//            cellStack.push(p);
//                  
//        }
//
//        else if (randDir == 4) {
//                
//            p->W->visited = true;
//            p->wW = false;
//            p = p->W;
//            p->wE = false;
//            cellStack.push(p);
//                   
//        }   
//
//        if (p == start)
//            fin = true;
//
//    }
//
//
//
//    Player player(100, 100);
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//          
//            //cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
//        }
//
//        ///Logic
//
//        if (Keyboard::isKeyPressed(Keyboard::Up))
//        {
//            player.moveUp();
//        }
//        if (Keyboard::isKeyPressed(Keyboard::Down))
//        {
//            player.moveDown();
//        }
//        if (Keyboard::isKeyPressed(Keyboard::Left))
//        {
//            player.moveLeft();
//        }
//        if (Keyboard::isKeyPressed(Keyboard::Right))
//        {
//            player.moveRight();
//        }
//
//        window.clear(Color::White);
//
//        for (int i = 0; i < X; i++) {
//
//            for (int j = 0; j < Y; j++) {
//
//                if (c[i][j]->wN == true) 
//                    window.draw(makeWalls(c[i][j]->x, c[i][j]->y, 'n'));
//
//                if (c[i][j]->wS == true)
//                    window.draw(makeWalls(c[i][j]->x, c[i][j]->y, 's'));
//
//                if (c[i][j]->wE == true)
//                    window.draw(makeWalls(c[i][j]->x, c[i][j]->y, 'e'));
//
//                if (c[i][j]->wW == true)
//                    window.draw(makeWalls(c[i][j]->x, c[i][j]->y, 'w'));
//
//            }
//
//        }
//
//        
//     
//        player.drawPlayer(window);
//
//        window.display();
//    }
//
//   
//
//    return 0;
//}

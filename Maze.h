#pragma once
#include"game.h"
#include"Cells.h"
#include"Pause.h"
#include"player.h"
#include"Item.h"
#include"Inventory.h"
#include "Enemy.h"
#include"GameOver.h"

Font font1;
Text text1;

Font font2;
Text text2;

Text lives;
int Total_lives = 3;

Text score;
int Total_score = 0;

RectangleShape makelines(int x, int y) {

    RectangleShape l;

    l.setFillColor(Color::Magenta);
    l.setSize(Vector2f(10, 10));
    l.setPosition(x, y);

    return l;

}

RectangleShape makeWalls(int x, int y, char a) {

    RectangleShape wall;

    int l = 60, w = 11;

    if (a == 'n') {

        wall.setPosition(x, y - l);
        wall.setFillColor(Color::Yellow);
        wall.setSize(Vector2f(l, w));

    }


    if (a == 's') {

        wall.setPosition(x, y);
        wall.setFillColor(Color::Yellow);
        wall.setSize(Vector2f(l, w));

    }


    if (a == 'e') {

        wall.setPosition(x + l, y - l);
        wall.setFillColor(Color::Yellow);
        wall.setSize(Vector2f(w, l + 11));

    }


    if (a == 'w') {

        wall.setPosition(x, y - l);
        wall.setFillColor(Color::Yellow);
        wall.setSize(Vector2f(w, l));

    }

    return wall;
}


class Maze
{
public:
    Maze() {}
    Maze(int width, int height) : width_(width), height_(height)
    {
                maze_ = new int[width_ * height_];
                std::fill_n(maze_, width_ * height_, 0);
    }
        
            ~Maze()
            {
                delete[] maze_;
           }
        
            void generate() {
                std::srand(std::time(nullptr));
                generateMazeRecursive(0, 0);
                setStartAndEnd();
            }
            void display(sf::RenderWindow& window, int cellSize) const {
                sf::Font font;
                if (!font.loadFromFile("C:\\Users\\LEGEND\\Documents\\Fast\\4 Sem\\Data\\Project\\DS-Project\\Graphics\\arcade_6896660\\ARCADE_R.ttf")) {
                    std::cerr << "Failed to load font" << std::endl;
                    return;
                }

                for (int y = 0; y < height_; ++y) {
                    for (int x = 0; x < width_; ++x) {
                        const int index = y * width_ + x;
                        if (maze_[index] == 0) {
                            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                            cell.setPosition(x * cellSize, y * cellSize);
                           // cell.setFillColor(sf::Color::Red);
                            window.draw(cell);
                        }
                        else if (maze_[index] == 2) {
                            sf::Text startText("Start", font, 16);
                            startText.setPosition(x * cellSize, y * cellSize);
                            startText.setFillColor(sf::Color::White);
                            window.draw(startText);
                        }
                        else if (maze_[index] == 3) {
                            sf::Text endText("End", font, 16);
                            endText.setPosition(x * cellSize, y * cellSize);
                            endText.setFillColor(sf::Color::White);
                            window.draw(endText);
                        }
                    }
                }
            }
            

            void generateMazeRecursive(int x, int y)
            {
                maze_[y * width_ + x] = 1;

                int directions[4] = { 0, 1, 2, 3 };
                shuffleArray(directions, 4);

                for (int i = 0; i < 4; ++i) {
                    switch (directions[i]) {
                    case 0: // Up
                        if (y - 2 >= 0 && maze_[(y - 2) * width_ + x] == 0) {
                            maze_[(y - 1) * width_ + x] = 1;
                            generateMazeRecursive(x, y - 2);
                        }
                        break;
                    case 1: // Right
                        if (x + 2 < width_ && maze_[y * width_ + (x + 2)] == 0) {
                            maze_[y * width_ + (x + 1)] = 1;
                            generateMazeRecursive(x + 2, y);
                        }
                        break;
                    case 2: // Down
                        if (y + 2 < height_ && maze_[(y + 2) * width_ + x] == 0) {
                            maze_[(y + 1) * width_ + x] = 1;
                            generateMazeRecursive(x, y + 2);
                        }
                        break;
                    case 3: // Left
                        if (x - 2 >= 0 && maze_[y * width_ + (x - 2)] == 0) {
                            maze_[y * width_ + (x - 1)] = 1;
                            generateMazeRecursive(x - 2, y);
                        }
                        break;
                    }
                }
            }

            void shuffleArray(int* arr, int size)
            {
                for (int i = size - 1; i > 0; --i) {
                    int j = std::rand() % (i + 1);
                    std::swap(arr[i], arr[j]);
                }
            }

            void setStartAndEnd()
            {
                // Set random starting and ending pathways

                // Set starting point
                int startX = rand() % width_;
                int startY = 0;
                maze_[startY * width_ + startX] = 2;

                // Set ending point
                int endX = rand() % width_;
                int endY = height_ - 1;
                maze_[endY * width_ + endX] = 3;
            }

    void Draw()
    {
        RenderWindow window2(VideoMode(1200, 650), "Enchanted Labyrinth Explorer");
        Sprite Background;
        Texture Bt;
        Bt.loadFromFile("C:\\Users\\munee\\OneDrive\\Desktop\\Semester 4\\Data Structures\\Project1\\Graphics\\Blue Illustration Game Presentation.png");
        Background.setTexture(Bt);
        Background.setScale(0.66, 0.6);

        RectangleShape test;
        test.setPosition(100, 100);
        test.setFillColor(Color::Blue);
        test.setSize(Vector2f(10, 10));
        bool left = false, right = false, up = false, down = false;

        const int X = 8, Y = 15;

        Cell cells[X][Y];
        Cell* c[X][Y];
        Cell pos[X][Y];

        for (int i = 0; i < X; i++) {

            for (int j = 0; j < Y; j++) {

                c[i][j] = &cells[i][j];

            }

        }

        for (int i = 0; i < X; i++) {

            for (int j = 0; j < Y; j++) {

                c[i][j]->x = 120 + j * 60;
                c[i][j]->y = 170 + i * 60;

                pos[i][j].x = 130 + j * 60;
                pos[i][j].y = 110 + i * 60;

                if (j < Y - 1)
                    c[i][j]->E = c[i][j + 1];

                if (i > 0)
                    c[i][j]->N = c[i - 1][j];

                if (i < X - 1)
                    c[i][j]->S = c[i + 1][j];

                if (j > 0)
                    c[i][j]->W = c[i][j - 1];

            }

        }

        Player P(pos[0][0].x, pos[0][0].y);
        Enemy E1(pos[7][12].x, pos[7][12].y + 15, "Graphics/Sprites/E1.png", 1.0f, 1.0f);
        Enemy E2(pos[6][6].x, pos[6][6].y + 15, "Graphics/Sprites/E1.png", 1.0f, 1.0f);
        //Enemy E3(pos[7][9].x, pos[7][9].y + 15, "Graphics/Sprites/E1.png", 1.0f, 1.0f);


        int dirE = 1;
        int posX = 0, posY = 0;

        ///FINISH FLAG
        Item flag(pos[7][14].x - 5, pos[7][14].y - 10, "Graphics/Sprites/finish.png", 0.05f, 0.05f, 100);

        Cell* start = c[0][0];
        Cell* p = start;
        c[0][0]->visited = true;

        srand(time(nullptr));

        int randDir = 0;

        bool fin = false;
        Stack<Cell*> cellStack;
        cellStack.push(start);

        Inventory<int> items;

        //// SETTING WEOPENS IN MAZE
        Item weapon1(c[5][2]->x, c[5][2]->y, "Graphics/Sprites/simpleSW.png", 0.95f, 0.95f, -1);
        Item weopon2(c[2][8]->x, c[2][8]->y, "Graphics/Sprites/intermediateSW.png", 0.95f, 0.95f, -2);
        Item weopon3(c[7][0]->x, c[7][0]->y - 60, "Graphics/Sprites/advancedSW.png", 0.95f, 0.95f, -3);

        //// SETTING POTIONS IN MAZE
        Item potion1(pos[6][5].x + 10, pos[6][5].y + 50, "Graphics/Sprites/potion1.png", 0.7f, 0.7f, 1);
        Item potion2(pos[5][0].x - 20, pos[5][0].y - 10, "Graphics/Sprites/potion2.png", 0.7f, 0.7f, 2);
        Item potion3(pos[7][7].x, pos[0][5].y - 10, "Graphics/Sprites/potion3.png", 0.7f, 0.7f, 3);
        Item potion4(pos[2][10].x + 10, pos[2][10].y + 15, "Graphics/Sprites/potion4.png", 0.03f, 0.03f, 4);

        //// RECURSIVE BACKTRACKING ALGORITHM
        while (!fin) {

            ////

            randDir = 0;

            if (p->N != NULL && p->N->visited == false)
                randDir = 1;

            else if (p->E != NULL && p->E->visited == false)
                randDir = 2;

            else if (p->S != NULL && p->S->visited == false)
                randDir = 3;

            else if (p->W != NULL && p->W->visited == false)
                randDir = 4;

            if ((p->N != NULL && p->N->visited == false) && (p->E != NULL && p->E->visited == false)) {

                randDir = rand() % 2;
                randDir += 1;

            }

            else if ((p->N != NULL && p->N->visited == false) && (p->W != NULL && p->W->visited == false)) {

                randDir = rand() % 2;


                switch (randDir) {
                case 0:
                    randDir = 1;
                    break;
                case 1:
                    randDir = 4;
                    break;

                }


            }

            else if ((p->N != NULL && p->N->visited == false) && (p->S != NULL && p->S->visited == false)) {

                randDir = rand() % 2;

                if (randDir == 0) {
                    randDir = 1;
                }
                else {
                    randDir = 3;
                }

            }

            else if ((p->E != NULL && p->E->visited == false) && (p->S != NULL && p->S->visited == false)) {

                randDir = rand() % 2;

                if (randDir == 0) {
                    randDir = 2;
                }
                else {
                    randDir = 3;
                }

            }

            else if ((p->E != NULL && p->E->visited == false) && (p->W != NULL && p->W->visited == false)) {

                randDir = rand() % 2;

                if (randDir == 0) {
                    randDir = 2;
                }
                else {
                    randDir = 4;
                }

            }

            else if ((p->S != NULL && p->S->visited == false) && (p->W != NULL && p->W->visited == false)) {

                randDir = rand() % 2;

                if (randDir == 0) {
                    randDir = 3;
                }
                else {
                    randDir = 4;
                }

            }

            if ((p->E != NULL && p->E->visited == false) && (p->S != NULL && p->S->visited == false) && (p->W != NULL && p->W->visited == false))
                randDir = rand() % 3 + 2;

            else if ((p->N != NULL && p->N->visited == false) && (p->S != NULL && p->S->visited == false) && (p->W != NULL && p->W->visited == false)) {

                randDir = rand() % 3;

                switch (randDir) {
                case 0:
                    randDir = 1;
                    break;
                case 1:
                    randDir = 3;
                    break;
                case 2:
                    randDir = 4;
                    break;
                }

            }

            else if ((p->N != NULL && p->N->visited == false) && (p->E != NULL && p->E->visited == false) && (p->W != NULL && p->W->visited == false)) {

                randDir = rand() % 3;

                switch (randDir) {
                case 0:
                    randDir = 1;
                    break;
                case 1:
                    randDir = 2;
                    break;
                case 2:
                    randDir = 4;
                    break;
                }

            }
            else if ((p->N != NULL && p->N->visited == false) && (p->E != NULL && p->E->visited == false) && (p->S != NULL && p->S->visited == false)) {

                randDir = rand() % 3;
                randDir += 1;

            }

            if ((p->N != NULL && p->N->visited == false) && (p->E != NULL && p->E->visited == false) && (p->S != NULL && p->S->visited == false) && (p->W != NULL && p->W->visited == false))
                randDir = rand() % 4 + 1;
           

            //// 
            if (randDir == 0) {

                cellStack.pop();
                p = cellStack.Top();

                if (p == start) {

                    fin = true;

                }

            }

            else if (randDir == 1) {

                p->N->visited = true;
                p->wN = false;
                p = p->N;
                p->wS = false;
                cellStack.push(p);

            }
            else if (randDir == 2) {

                p->E->visited = true;
                p->wE = false;
                p = p->E;
                p->wW = false;
                cellStack.push(p);

            }

            else if (randDir == 3) {

                p->S->visited = true;
                p->wS = false;
                p = p->S;
                p->wN = false;
                cellStack.push(p);

            }

            else if (randDir == 4) {

                p->W->visited = true;
                p->wW = false;
                p = p->W;
                p->wE = false;
                cellStack.push(p);

            }

            p->visited = true;

            if (p == start)
                fin = true;

        }

        while (window2.isOpen())
        {

            //cout << Mouse::getPosition(window2).x << " " << Mouse::getPosition(window2).y << endl;
            Event event2;
            while (window2.pollEvent(event2))
            {
                if (event2.type == Event::Closed)
                    window2.close();
                if(event2.key.code == Keyboard::Escape)
                    window2.close();
                if (event2.key.code == Keyboard::P)
                {
                    //// PAUSE MENU
                    Pause p;
                    int se = 0;
                    p.display_Pause(se);
                    if (se == 1)
                    {
                        window2.close();
                    }
                }
                if (event2.key.code == Keyboard::I)
                {
                    items.Draw();
                }

                //// PLAYER MOVEMENT WITH COLLISION DETECTION
                if (Keyboard::isKeyPressed(Keyboard::Up))
                {
                    

                    if (posX > 0) {

                        if (c[posX][posY]->N != NULL && c[posX][posY]->wN == false) {

                            posX--;
                            P.sprite.setPosition(pos[posX][posY].x, pos[posX][posY].y);
                            //cout << pos[posX][posY].x << " " << pos[posX][posY].y << endl;

                        }


                    }
                        

                }
                if (Keyboard::isKeyPressed(Keyboard::Down))
                {
                    //GameOver();


                    if (posX < 7) {

                        if (c[posX][posY]->S != NULL && c[posX][posY]->wS == false) {

                            posX++;
                            P.sprite.setPosition(pos[posX][posY].x, pos[posX][posY].y);
                            //cout << pos[posX][posY].x << " " << pos[posX][posY].y << endl;

                        }


                    }

                }
                if (Keyboard::isKeyPressed(Keyboard::Left))
                {
                    
                    if (posY > 0) {

                        if (c[posX][posY]->W != NULL && c[posX][posY]->wW == false) {

                            posY--;
                            P.sprite.setPosition(pos[posX][posY].x, pos[posX][posY].y);
                            //cout << pos[posX][posY].x << " " << pos[posX][posY].y << endl;

                        }


                    }


                }
                if (Keyboard::isKeyPressed(Keyboard::Right))
                {
               

                    if (posY < 14) {

                        if (c[posX][posY]->E != NULL && c[posX][posY]->wE == false) {

                            posY++;
                            P.sprite.setPosition(pos[posX][posY].x, pos[posX][posY].y);
                            //cout << pos[posX][posY].x << " " << pos[posX][posY].y << endl;

                        }


                    }

                }



                
            }


            window2.draw(Background);

            //// MAKING WALLS
            for (int i = 0; i < X; i++) {

                for (int j = 0; j < Y; j++) {

                    if (c[i][j]->wN == true)
                        window2.draw(makeWalls(c[i][j]->x, c[i][j]->y, 'n'));

                    if (c[i][j]->wS == true)
                        window2.draw(makeWalls(c[i][j]->x, c[i][j]->y, 's'));

                    if (c[i][j]->wE == true)
                        window2.draw(makeWalls(c[i][j]->x, c[i][j]->y, 'e'));

                    if (c[i][j]->wW == true)
                        window2.draw(makeWalls(c[i][j]->x, c[i][j]->y, 'w'));


                }

            }

            ///// SHORTEST PATH
            
            for (int i = 0; i < X; i++) {

                for (int j = 0; j < Y; j++) {

                    if (c[i][j]->line == true) {

                        window2.draw(makelines(pos[i][j].x, pos[i][j].y));

                    }

                }

            }

            //// DISPLAYING SCORE/////////
            font1.loadFromFile("C:\\Users\\munee\\OneDrive\\Desktop\\Semester 4\\Data Structures\\Project1\\Graphics\\arcade_6896660\\ARCADE_I.ttf");
            text1.setFont(font1);
            text1.setFillColor(Color::White);
            text1.setString("Total Score:");
            text1.setCharacterSize(15);
            text1.setPosition(20, 16);

            score.setString(to_string(Total_score));
            score.setFont(font1);
            score.setPosition(210, 16);
            score.setScale(0.5f, 0.5f);
            score.setFillColor(Color::White);

            //// DISPLAYING LIVES////////
            font2.loadFromFile("C:\\Users\\munee\\OneDrive\\Desktop\\Semester 4\\Data Structures\\Project1\\Graphics\\arcade_6896660\\ARCADE_I.ttf");
            text2.setFont(font2);
            text2.setFillColor(Color::White);
            text2.setString("Lives:");
            text2.setCharacterSize(15);
            text2.setPosition(1020, 16);
 
            lives.setString(to_string(Total_lives));
            lives.setFont(font1);
            lives.setPosition(1120, 16);
            lives.setScale(0.5f, 0.5f);
            lives.setFillColor(Color::White);

            
           
            //// DISPLAYING FUNCTIONS         
            weapon1.drawItem(window2);
            weopon2.drawItem(window2);
            weopon3.drawItem(window2);
            potion1.drawItem(window2);
            potion2.drawItem(window2);
            potion3.drawItem(window2);
            potion4.drawItem(window2);


            P.drawPlayer(window2);
            E1.drawPlayer(window2);
            window2.draw(text1);
            window2.draw(text2);
            window2.draw(lives);
            window2.draw(score);

            flag.drawItem(window2);

            Sprite gameover;
            Texture gameov;


            gameov.loadFromFile("Graphics/gameOver.png");
            gameover.setTexture(gameov);
          //  gameover.setScale()

            ///// COLLISIONS 
            if (P.sprite.getGlobalBounds().intersects(weapon1.sprite.getGlobalBounds())) {

                items.insert(weapon1.key, "weopon", "simple sword");
                weapon1.sprite.setPosition(-1000, -1000);
                Total_score += 100;

            }

            if (P.sprite.getGlobalBounds().intersects(weopon2.sprite.getGlobalBounds())) {

                items.insert(weopon2.key, "weopon", "intrmediate sword");
                weopon2.sprite.setPosition(-1000, -1000);
                Total_score += 250;

            }

            if (P.sprite.getGlobalBounds().intersects(weopon3.sprite.getGlobalBounds())) {

                items.insert(weopon3.key, "weopon", "advance sword");
                weopon3.sprite.setPosition(-1000, -1000);
                Total_score += 500;

            }

            if (P.sprite.getGlobalBounds().intersects(potion1.sprite.getGlobalBounds())) {

                items.insert(potion1.key, "potion", "potion1");
                potion1.sprite.setPosition(-1000, -1000);
                Total_lives++;

            }

            if (P.sprite.getGlobalBounds().intersects(potion2.sprite.getGlobalBounds())) {

                items.insert(potion2.key, "potion", "potion2");
                potion2.sprite.setPosition(-1000, -1000);
                Total_lives++;

            }

            if (P.sprite.getGlobalBounds().intersects(potion3.sprite.getGlobalBounds())) {

                items.insert(potion3.key, "potion", "potion3");
                potion3.sprite.setPosition(-1000, -1000);
                Total_lives++;

            }

            if (P.sprite.getGlobalBounds().intersects(potion4.sprite.getGlobalBounds())) {

                items.insert(potion4.key, "potion", "potion4");
                potion4.sprite.setPosition(-1000, -1000);
                Total_lives++;

            }

            if (P.sprite.getGlobalBounds().intersects(E1.sprite.getGlobalBounds())) {

                if (Total_lives > -1){
                
                    E1.sprite.setPosition(-1000, -1000);
                    Total_lives--;
                    //posX = 0, posY = 0;
                
                }
                
            }

            if (P.sprite.getGlobalBounds().intersects(E2.sprite.getGlobalBounds())) {

                if (Total_lives > -1) {

                    E2.sprite.setPosition(-1000, -1000);
                    Total_lives--;
                    //posX = 0, posY = 0;

                }

               
            }

            //if (P.sprite.getGlobalBounds().intersects(E3.sprite.getGlobalBounds())) {

            //    if (Total_lives > -1) {

            //        E3.sprite.setPosition(-1000, -1000);
            //        Total_lives--;
            //        //posX = 0, posY = 0;

            //    }

            //}

            if (P.sprite.getGlobalBounds().intersects(flag.sprite.getGlobalBounds())) {
                
             //  RenderWindow window3(VideoMode(1200, 650), "Game Over");
               //window3.draw(gameover);
                GameOver();
                window2.close();
            }

            if (Total_lives == 0) {

                window2.close();

            }

            window2.draw(E2.sprite);
            //window2.draw(E3.sprite);

            //// ENEMY MOVEMENT
            if (E1.sprite.getPosition().x < 790)
                dirE = 1;

            if (E1.sprite.getPosition().x > 940)
                dirE = -1;

            if (dirE == 1)
                E1.moveRight();

            else
                E1.moveLeft();

            window2.display();
        }
        
    }
    private:
    
            int width_;
            int height_;
            int* maze_;
 };
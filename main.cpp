#include"window.h"

using namespace std;

int main()
{
	Welcome welcome;
	welcome.Display_Welcome();
	return 0;
}
//
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <string>
//
//struct Item {
//    std::string name;
//    sf::Sprite sprite;
//    // Additional attributes as needed
//};
//
//struct AVLNode {
//    Item item;
//    AVLNode* left;
//    AVLNode* right;
//    int height;
//
//    AVLNode(const Item& item) : item(item), left(nullptr), right(nullptr), height(1) {}
//};
//
//class InventoryManager {
//private:
//    AVLNode* root;
//
//    int height(AVLNode* node) {
//        if (node == nullptr) return 0;
//        return node->height;
//    }
//
//    int balanceFactor(AVLNode* node) {
//        if (node == nullptr) return 0;
//        return height(node->left) - height(node->right);
//    }
//
//    AVLNode* rotateRight(AVLNode* y) {
//        AVLNode* x = y->left;
//        AVLNode* T2 = x->right;
//
//        // Perform rotation
//        x->right = y;
//        y->left = T2;
//
//        // Update heights
//        y->height = std::max(height(y->left), height(y->right)) + 1;
//        x->height = std::max(height(x->left), height(x->right)) + 1;
//
//        return x;
//    }
//
//    AVLNode* rotateLeft(AVLNode* x) {
//        AVLNode* y = x->right;
//        AVLNode* T2 = y->left;
//
//        // Perform rotation
//        y->left = x;
//        x->right = T2;
//
//        // Update heights
//        x->height = std::max(height(x->left), height(x->right)) + 1;
//        y->height = std::max(height(y->left), height(y->right)) + 1;
//
//        return y;
//    }
//
//    AVLNode* balance(AVLNode* node) {
//        if (node == nullptr) return node;
//
//        int bf = balanceFactor(node);
//
//        // Left Heavy
//        if (bf > 1) {
//            if (balanceFactor(node->left) < 0) {
//                node->left = rotateLeft(node->left);
//            }
//            return rotateRight(node);
//        }
//        // Right Heavy
//        if (bf < -1) {
//            if (balanceFactor(node->right) > 0) {
//                node->right = rotateRight(node->right);
//            }
//            return rotateLeft(node);
//        }
//
//        return node;
//    }
//
//    AVLNode* insert(AVLNode* node, const Item& item) {
//        if (node == nullptr) return new AVLNode(item);
//
//        if (item.name < node->item.name) {
//            node->left = insert(node->left, item);
//        }
//        else if (item.name > node->item.name) {
//            node->right = insert(node->right, item);
//        }
//        else {
//            // Duplicate names not allowed
//            return node;
//        }
//
//        node->height = 1 + std::max(height(node->left), height(node->right));
//
//        return balance(node);
//    }
//
//    AVLNode* minValueNode(AVLNode* node) {
//        AVLNode* current = node;
//
//        while (current->left != nullptr) {
//            current = current->left;
//        }
//
//        return current;
//    }
//
//    AVLNode* deleteNode(AVLNode* root, const std::string& itemName) {
//        if (root == nullptr) return root;
//
//        if (itemName < root->item.name) {
//            root->left = deleteNode(root->left, itemName);
//        }
//        else if (itemName > root->item.name) {
//            root->right = deleteNode(root->right, itemName);
//        }
//        else {
//            if (root->left == nullptr || root->right == nullptr) {
//                AVLNode* temp = root->left ? root->left : root->right;
//
//                if (temp == nullptr) {
//                    temp = root;
//                    root = nullptr;
//                }
//                else {
//                    *root = *temp;
//                }
//
//                delete temp;
//            }
//            else {
//                AVLNode* temp = minValueNode(root->right);
//                root->item = temp->item;
//                root->right = deleteNode(root->right, temp->item.name);
//            }
//        }
//
//        if (root == nullptr) return root;
//
//        root->height = 1 + std::max(height(root->left), height(root->right));
//
//        return balance(root);
//    }
//
//    AVLNode* search(AVLNode* node, const std::string& itemName) {
//        if (node == nullptr || node->item.name == itemName) {
//            return node;
//        }
//
//        if (itemName < node->item.name) {
//            return search(node->left, itemName);
//        }
//
//        return search(node->right, itemName);
//    }
//
//public:
//    InventoryManager() : root(nullptr) {}
//
//    void addItem(const Item& item) {
//        root = insert(root, item);
//    }
//
//    void deleteItem(const std::string& itemName) {
//        root = deleteNode(root, itemName);
//    }
//
//    Item retrieveItem(const std::string& itemName) {
//        AVLNode* node = search(root, itemName);
//        if (node) {
//            return node->item;
//        }
//        else {
//            // Item not found
//            return Item{ "", sf::Sprite() };
//        }
//    }
//};
//
//int main() {
//    // Initialize SFML window, textures, sprites, etc.
//
//    // Example usage
//    InventoryManager inventory;
//    sf::Sprite swordSprite, potionSprite;
//
//    Item sword{ "Sword", swordSprite };
//    Item potion{ "Potion", potionSprite };
//
//    inventory.addItem(sword);
//    inventory.addItem(potion);
//
//    Item retrievedSword = inventory.retrieveItem("Sword");
//    if (retrievedSword.name != "") {
//        // Display the sword sprite
//        // window.draw(retrievedSword.sprite);
//    }
//
//    inventory.deleteItem("Potion");
//
//    return 0;
//}
//
//
////#include <SFML/Graphics.hpp>
////#include <iostream>
////#include <random>
////#include <ctime>
////
////class Maze {
////public:
////    Maze(int width, int height) : width_(width), height_(height) {
////        maze_ = new int[width_ * height_];
////        std::fill_n(maze_, width_ * height_, 0);
////    }
////
////    ~Maze() {
////        delete[] maze_;
////    }
////
////    void generate() {
////        std::srand(std::time(nullptr));
////        generateMazeRecursive(0, 0);
////    }
////
////    void display(sf::RenderWindow& window, int cellSize) const {
////        for (int y = 0; y < height_; ++y) {
////            for (int x = 0; x < width_; ++x) {
////                const int index = y * width_ + x;
////                if (maze_[index] == 0) {
////                    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
////                    cell.setPosition(x * cellSize, y * cellSize);
////                    cell.setFillColor(sf::Color::Red);
////                    window.draw(cell);
////                }
////            }
////        }
////    }
////
////private:
////    void generateMazeRecursive(int x, int y) {
////        maze_[y * width_ + x] = 1;
////
////        int directions[4] = { 0, 1, 2, 3 };
////        shuffleArray(directions, 4);
////
////        for (int i = 0; i < 4; ++i) {
////            switch (directions[i]) {
////            case 0: // Up
////                if (y - 2 >= 0 && maze_[(y - 2) * width_ + x] == 0) {
////                    maze_[(y - 1) * width_ + x] = 1;
////                    generateMazeRecursive(x, y - 2);
////                }
////                break;
////            case 1: // Right
////                if (x + 2 < width_ && maze_[y * width_ + (x + 2)] == 0) {
////                    maze_[y * width_ + (x + 1)] = 1;
////                    generateMazeRecursive(x + 2, y);
////                }
////                break;
////            case 2: // Down
////                if (y + 2 < height_ && maze_[(y + 2) * width_ + x] == 0) {
////                    maze_[(y + 1) * width_ + x] = 1;
////                    generateMazeRecursive(x, y + 2);
////                }
////                break;
////            case 3: // Left
////                if (x - 2 >= 0 && maze_[y * width_ + (x - 2)] == 0) {
////                    maze_[y * width_ + (x - 1)] = 1;
////                    generateMazeRecursive(x - 2, y);
////                }
////                break;
////            }
////        }
////    }
////
////    void shuffleArray(int* arr, int size) {
////        for (int i = size - 1; i > 0; --i) {
////            int j = std::rand() % (i + 1);
////            std::swap(arr[i], arr[j]);
////        }
////    }
////
////    int width_;
////    int height_;
////    int* maze_;
////};
////
////int main() {
////    const int width = 10;
////    const int height = 10;
////    const int cellSize = 25;
////
////    Maze maze(width, height);
////    maze.generate();
////
////    sf::RenderWindow window(sf::VideoMode(width * cellSize, height * cellSize), "Maze");
////
////    while (window.isOpen()) {
////        sf::Event event;
////        while (window.pollEvent(event)) {
////            if (event.type == sf::Event::Closed)
////                window.close();
////        }
////
////        window.clear();
////
////        maze.display(window, cellSize);
////
////        window.display();
////    }
////
////    return 0;
////}
////
////
////
//////#include <iostream>
//////#include <random>
//////#include <ctime>
//////
//////class Maze {
//////public:
//////    Maze(int width, int height) : width_(width), height_(height) {
//////        maze_ = new int[width_ * height_];
//////        std::fill_n(maze_, width_ * height_, 0);
//////    }
//////
//////    ~Maze() {
//////        delete[] maze_;
//////    }
//////
//////    void generate() {
//////        std::srand(std::time(nullptr));
//////        generateMazeRecursive(0, 0);
//////    }
//////
//////    void print() const {
//////        for (int y = 0; y < height_; ++y) {
//////            for (int x = 0; x < width_; ++x) {
//////                const int index = y * width_ + x;
//////                if (maze_[index] == 0)
//////                    std::cout << "# ";
//////                else
//////                    std::cout << "  ";
//////            }
//////            std::cout << std::endl;
//////        }
//////    }
//////
//////private:
//////    void generateMazeRecursive(int x, int y) {
//////        maze_[y * width_ + x] = 1;
//////
//////        int directions[4] = { 0, 1, 2, 3 };
//////        shuffleArray(directions, 4);
//////
//////        for (int i = 0; i < 4; ++i) {
//////            switch (directions[i]) {
//////            case 0: // Up
//////                if (y - 2 >= 0 && maze_[(y - 2) * width_ + x] == 0) {
//////                    maze_[(y - 1) * width_ + x] = 1;
//////                    generateMazeRecursive(x, y - 2);
//////                }
//////                break;
//////            case 1: // Right
//////                if (x + 2 < width_ && maze_[y * width_ + (x + 2)] == 0) {
//////                    maze_[y * width_ + (x + 1)] = 1;
//////                    generateMazeRecursive(x + 2, y);
//////                }
//////                break;
//////            case 2: // Down
//////                if (y + 2 < height_ && maze_[(y + 2) * width_ + x] == 0) {
//////                    maze_[(y + 1) * width_ + x] = 1;
//////                    generateMazeRecursive(x, y + 2);
//////                }
//////                break;
//////            case 3: // Left
//////                if (x - 2 >= 0 && maze_[y * width_ + (x - 2)] == 0) {
//////                    maze_[y * width_ + (x - 1)] = 1;
//////                    generateMazeRecursive(x - 2, y);
//////                }
//////                break;
//////            }
//////        }
//////    }
//////
//////    void shuffleArray(int* arr, int size) {
//////        for (int i = size - 1; i > 0; --i) {
//////            int j = std::rand() % (i + 1);
//////            std::swap(arr[i], arr[j]);
//////        }
//////    }
//////
//////    int width_;
//////    int height_;
//////    int* maze_;
//////};
//////
//////int main() {
//////    const int width = 25;
//////    const int height = 25;
//////
//////    Maze maze(width, height);
//////    maze.generate();
//////    maze.print();
//////
//////    return 0;
//////}
////
//////#include<SFML/Graphics.hpp>
//////
//////int main()
//////{
//////	sf::RenderWindow window(sf::VideoMode(800, 600), "Title");
//////	sf::Event event;
//////
//////	while (window.isOpen()) {
//////
//////		while (window.pollEvent(event)) {
//////
//////			if (event.type == sf::Event::Closed) {
//////
//////				window.close();
//////			}
//////		}
//////	}
//////	return 0;
//////}
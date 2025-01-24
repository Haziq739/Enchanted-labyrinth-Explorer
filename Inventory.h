#pragma once
#include"game.h"
#pragma once
template<typename T>
struct AVLInventoryNode
{
    T value;
    string Type;
    string Name;
    AVLInventoryNode<T>* left;
    AVLInventoryNode<T>* right;
    int height;

    AVLInventoryNode(T d, const string T, const string N) : value(d), left(nullptr), right(nullptr), height(1), Name(N), Type(T) {}

};

template<typename T>
class Inventory
{
private:
    AVLInventoryNode<T>* root;

public:
    Inventory() : root(nullptr) {}

    int getHeight(AVLInventoryNode<T>* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(AVLInventoryNode<T>* node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(AVLInventoryNode<T>* node)
    {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = 1 + max(leftHeight, rightHeight);
    }

    AVLInventoryNode<T>* rotateRight(AVLInventoryNode<T>* node)
    {
        AVLInventoryNode<T>* newRoot = node->left;
        AVLInventoryNode<T>* newRootRight = newRoot->right;

        newRoot->right = node;
        node->left = newRootRight;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    AVLInventoryNode<T>* rotateLeft(AVLInventoryNode<T>* node)
    {
        AVLInventoryNode<T>* newRoot = node->right;
        AVLInventoryNode<T>* newRootLeft = newRoot->left;

        newRoot->left = node;
        node->right = newRootLeft;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    AVLInventoryNode<T>* insertNode(AVLInventoryNode<T>* node, T value, const string N, const string Type)
    {
        if (node == nullptr)
            return new AVLInventoryNode<T>(value, Type, N);

        if (value < node->value)
            node->left = insertNode(node->left, value, N, Type);
        else if (value > node->value)
            node->right = insertNode(node->right, value, N, Type);
        else
            return node;

        updateHeight(node);

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->value)
            return rotateRight(node);

        if (balanceFactor < -1 && value > node->right->value)
            return rotateLeft(node);

        if (balanceFactor > 1 && value > node->left->value)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balanceFactor < -1 && value < node->right->value)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }
    void Draw()
    {
        Sprite s;
        Texture st;
        st.loadFromFile("Graphics/Inventory.png");
        s.setTexture(st);
        s.setScale(0.3f, 0.3f);

        Sprite swords[3];
        Sprite potions[4];
        Texture texture_[7];
        texture_[0].loadFromFile("Graphics/Sprites/simpleSW.png");
        texture_[1].loadFromFile("Graphics/Sprites/intermediateSW.png");
        texture_[2].loadFromFile("Graphics/Sprites/advancedSW.png");
        texture_[3].loadFromFile("Graphics/Sprites/potion1.png");
        texture_[4].loadFromFile("Graphics/Sprites/potion2.png");
        texture_[5].loadFromFile("Graphics/Sprites/potion3.png");
        texture_[6].loadFromFile("Graphics/Sprites/potion4.png");
        swords[0].setTexture(texture_[0]);
        swords[1].setTexture(texture_[1]);
        swords[2].setTexture(texture_[2]);
        potions[0].setTexture(texture_[3]);
        potions[1].setTexture(texture_[4]);
        potions[2].setTexture(texture_[5]);
        potions[3].setTexture(texture_[6]);
        swords[0].setScale(1, 1);
        swords[1].setScale(1, 1);
        swords[2].setScale(1, 1);
        potions[0].setScale(0.9, 0.9);
        potions[1].setScale(0.9, 0.9);
        potions[2].setScale(0.9, 0.9);
        potions[3].setScale(0.04, 0.04);
        swords[0].setPosition(100, 100);
        swords[1].setPosition(150, 100);
        swords[2].setPosition(200, 100);
        potions[0].setPosition(100, 150);
        potions[1].setPosition(150, 150);
        potions[2].setPosition(200, 150);
        potions[3].setPosition(300, 150);




        RenderWindow win(VideoMode(500, 300), "Inventory");
        while (win.isOpen())
        {
            Event ie;
            while (win.pollEvent(ie))
            {
                if (ie.type == Event::Closed)
                    win.close();
                if (ie.key.code == Keyboard::Escape)
                    win.close();
                if (ie.key.code == Keyboard::Q)
                {
                    win.close();
                }

            }

            win.clear();
            win.draw(s);

            IDisplay(win, swords, potions);

            win.display();
        }

    }

    void insert(T value, const string T, const string N)
    {
        root = insertNode(root, value, N, T);
    }

    void display(AVLInventoryNode<T>* node, RenderWindow& win, Sprite* s, Sprite* p)
    {
        if (node != nullptr)
        {
            display(node->left, win, s, p);
            if (node->value == -3)
            {
                win.draw(s[2]);
            }
            else if (node->value == -2)
            {
                win.draw(s[1]);
            }
            else if (node->value == -1)
            {
                win.draw(s[0]);
            }
            else if (node->value == 1)
            {
                win.draw(p[0]);
            }
            else if (node->value == 2)
            {
                win.draw(p[1]);
            }
            else if (node->value == 3)
            {
                win.draw(p[2]);
            }
            else if (node->value == 4)
            {
                win.draw(p[3]);
            }
            display(node->right, win, s, p);
        }
    }

    void IDisplay(RenderWindow& win, Sprite* s, Sprite* p)
    {
        display(root, win, s, p);
    }

    void inOrderTraversal(AVLInventoryNode<T>* node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            cout << node->Type << " ,";
            cout << node->Type << " ,";
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }
    void preOrderTraversal(AVLInventoryNode<T>* node)
    {
        if (node != nullptr)
        {
            cout << node->Type << " ,";
            cout << node->Type << " ,";
            cout << node->value << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }
    void postOrderTraversal(AVLInventoryNode<T>* node)
    {
        if (node != nullptr)
        {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->Type << " ,";
            cout << node->Type << " ,";
            cout << node->value << " ";

        }
    }
    AVLInventoryNode<T>* findMinNode(AVLInventoryNode<T>* node)
    {
        if (node == nullptr)
            return nullptr;

        while (node->left != nullptr)
            node = node->left;

        return node;
    }
    AVLInventoryNode<T>* findMax(AVLInventoryNode<T>* node) {
        if (node == nullptr)
            return nullptr;

        while (node->right != nullptr)
            node = node->right;

        return node;
    }
    T Smallest()
    {
        AVLInventoryNode<T>* smallest = findMinNode(root);
        return smallest->value;
    }
    T Largest()
    {
        AVLInventoryNode<T>* Largest = findMax(root);
        return Largest->value;
    }


    AVLInventoryNode<T>* deleteNode(AVLInventoryNode<T>* node, T value)
    {
        if (node == nullptr)
            return node;

        if (value < node->value)
            node->left = deleteNode(node->left, value);
        else if (value > node->value)
            node->right = deleteNode(node->right, value);
        else
        {

            if (node->left == nullptr || node->right == nullptr)
            {
                AVLInventoryNode<T>* temp = node->left ? node->left : node->right;

                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                    delete temp;
                }
            }
            else
            {
                AVLInventoryNode<T>* temp = findMinNode(node->right);

                node->value = temp->value;

                node->right = deleteNode(node->right, temp->value);
            }
        }

        if (node == nullptr)
            return node;

        updateHeight(node);

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(node);

        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);

        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void remove(T value)
    {
        root = deleteNode(root, value);
    }

    bool isAVL(AVLInventoryNode<T>* node) {
        if (node == nullptr)
            return true;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        if ((leftHeight - rightHeight) > 1 || (leftHeight - rightHeight) < -1)
            return false;

        return isAVL(node->left) && isAVL(node->right);
    }

    void inOrderTraversal()
    {
        inOrderTraversal(root);
    }
    void preOrderTraversal()
    {
        preOrderTraversal(root);
    }
    void postOrderTraversal()
    {
        postOrderTraversal(root);
    }
};


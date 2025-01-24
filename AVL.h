#pragma once
template<typename T>
struct AVLInventoryNode
{
    T data;
    AVLInventoryNode* left;
    AVLInventoryNode* right;
    int height;

    AVLInventoryNode(T d) : data(d), left(nullptr), right(nullptr), height(1) {}
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

    AVLInventoryNode<T>* insertNode(AVLInventoryNode<T>* node, T data)
    {
        if (node == nullptr)
            return new AVLInventoryNode<T>(data);

        if (data < node->data)
            node->left = insertNode(node->left, data);
        else if (data > node->data)
            node->right = insertNode(node->right, data);
        else
            return node;

        updateHeight(node);

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && data < node->left->data)
            return rotateRight(node);

        if (balanceFactor < -1 && data > node->right->data)
            return rotateLeft(node);

        if (balanceFactor > 1 && data > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balanceFactor < -1 && data < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void insert(T data)
    {
        root = insertNode(root, data);
    }

    void inOrderTraversal(AVLInventoryNode<T>* node)
    {
        if (node != nullptr)
        {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }
    void preOrderTraversal(AVLInventoryNode<T>* node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
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
            cout << node->data << " ";

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
        return smallest->data;
    }
    T Largest()
    {
        AVLInventoryNode<T>* Largest = findMax(root);
        return Largest->data;
    }


    AVLInventoryNode<T>* deleteNode(AVLInventoryNode<T>* node, T data)
    {
        if (node == nullptr)
            return node;

        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
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
                AVLInventoryNode<T>* temp = findMinNode(node->left);

                node->data = temp->data;

                node->left = deleteNode(node->left, temp->data);
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

    void remove(T data)
    {
        root = deleteNode(root, data);
    }

    bool isAVL(AVLInventoryNode<T>* root) {
        if (root == nullptr)
            return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if ((leftHeight - rightHeight) > 1 || (leftHeight - rightHeight) < -1)
            return false;

        return isAVL(root->left) && isAVL(root->right);
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
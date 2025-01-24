#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct BSTNode {
	BSTNode<T>* left;
	BSTNode<T>* right;
	T data;
	BSTNode(T dta) :left(nullptr), right(nullptr), data(dta) {}

};

template<typename T>
class BST
{
private:
	BSTNode<T>* root;
	int size;
	BSTNode<T>* insertrec(BSTNode<T>* node, T item)
	{

		if (node == nullptr)
		{
			return new BSTNode<T>(item);
		}
		else
		{

			if (item < node->data)
			{
				node->left = insertrec(node->left, item);
			}
			else if (item > node->data)
			{
				node->right = insertrec(node->right, item);
			}
			else
			{
				cout << "\nDuplicate Not Added.\n";
			}
			return node;
		}

	}

	bool searchrec(BSTNode<T>* node, T item)
	{
		if (node == nullptr)
		{
			return false;
		}
		else
		{
			if (node->data == item)
			{
				return true;
			}
			else if (item < node->data)
			{
				searchrec(node->left, item);
			}
			else
			{
				searchrec(node->right, item);
			}

		}
	}

	BSTNode<T>* findMin(BSTNode<T>* node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}


	BSTNode<T>* removerec(BSTNode<T>* node, T key)
	{
		if (node == nullptr)
		{
			return node;
		}
		if (key < node->data)
		{
			node->left = removeNode(node->left, key);
		}
		else if (key > node->data) {
			node->right = removeNode(node->right, key);
		}
		else
		{
			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				node = nullptr;
			}
			else if (node->left == nullptr)
			{
				BSTNode<T>* temp = node;
				node = node->right;
				delete temp;
			}
			else if (node->right == nullptr)
			{
				BSTNode<T>* temp = node;
				node = node->left;
				delete temp;
			}
			else
			{
				BSTNode<T>* temp = findMin(node->right);
				node->data = temp->data;
				node->right = removeNode(node->right, temp->data);
			}
		}
		return node;

	}
	void inorderTraversal(BSTNode<T>* node) {
		if (node == nullptr)
		{
			return;
		}

		inorderTraversal(node->left);
		cout << node->data << " ";
		inorderTraversal(node->right);
	}
	void preorderTraversal(BSTNode<T>* node)
	{
		if (node == nullptr)
		{
			return;
		}

		cout << node->data << " ";
		preorderTraversal(node->left);
		preorderTraversal(node->right);

	}
	void postorderTraversal(BSTNode<T>* node)
	{
		if (node == nullptr)
		{
			return;
		}

		postorderTraversal(node->left);
		postorderTraversal(node->right);
		cout << node->data << " ";

	}

public:
	BST() :root(nullptr), size(0) {}
	bool empty()const;
	void insert(T dta);
	bool search(T key);
	void remove(T key);
	T minValue();
	T maxValue();
	int getHeight();
	int getSize();
	bool isBST();
	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();

};

template<typename T>
bool BST<T>::empty()const { return root == nullptr; }
template<typename T>
void BST<T>::insert(T dta) {
	if (empty())
	{
		root = new binaryTreeNode<T>(dta);
	}
	else
		insertrec(root, dta);

}

template<typename T>
bool BST<T>::search(T key)
{
	return searchrec(root, key);

}

template<typename T>
void BST<T>::remove(T key)
{
	root = removerec(root, key);

}

template<typename T>
void BST<T>::inorderTraversal() {
	inorderTraversal(root);
}

template<typename T>
void BST<T>::preorderTraversal()
{
	preorderTraversal(root);
}

template<typename T>
void BST<T>::postorderTraversal()
{
	postorderTraversal(root);
}

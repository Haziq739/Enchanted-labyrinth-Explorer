#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct Node {
	T value;
	Node<T>* next;
	Node(T d) :next(nullptr), value(d) {}
};

template<typename T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* current;
public:
	LinkedList() :head(nullptr), current(head) {}
	Node<T>* getHead()const;
	bool isEmpty()const;
	void insertatHead(T d);
	void insertatEnd(T d);
	void insertAt(T d, int index);
	T removeAt(int index);
	T removeatHead();
	T removeatEnd();
	bool search(T d, int& index);
	int ListLength();
	void Revarsal();
	LinkedList& operator+(LinkedList<T>& other);
	LinkedList& operator=(LinkedList<T>& other);

};

template<typename T>
Node<T>* LinkedList<T>::getHead()const { return head; }


template<typename T>
bool LinkedList<T>::isEmpty()const { return head == nullptr; }

template<typename T>
void LinkedList<T>::insertatHead(T d) {
	Node<T>* newNode = new Node<T>(d);
	newNode->next = head;
	head = newNode;
}

template<typename T>
void LinkedList<T>::insertatEnd(T d) {
	Node<T>* newNode = new Node<T>(d);
	if (isEmpty())
	{
		head = newNode;
		current = head;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
		current = current->next;
	}

}

template<typename T>
void LinkedList<T>::insertAt(T d, int index) {
	Node<T>* newNode = new Node<T>(d);
	Node<T>* temp = head;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	if (temp == head && (index - 1) < 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		newNode->next = temp->next;
		temp->next = newNode;
	}
}


template<typename T>
T LinkedList<T>::removeAt(int index) {
	if (isEmpty()) {
		cout << "List is empty, cannot remove anymore." << endl;
		return T();
	}

	if (index < 0) {
		cout << "Invalid index." << endl;
		return T();
	}

	T val;

	if (index == 0) {
		Node<T>* temp = head;
		head = head->next;
		val = temp->value;
		delete temp;
	}
	else {
		Node<T>* temp = head;
		Node<T>* prev = nullptr;
		int count = 0;

		while (temp != nullptr && count < index) {
			prev = temp;
			temp = temp->next;
			count++;
		}

		if (temp != nullptr) {
			prev->next = temp->next;
			val = temp->value;
			delete temp;
		}
		else {
			cout << "Invalid index." << endl;
			return T();
		}
	}

	return val;
}

template<typename T>
T LinkedList<T>::removeatHead() {
	T val;
	if (isEmpty())
	{
		cout << "\nList is Empty cannot Remove anymore\n";
	}
	else
	{
		Node<T>* temp = head;
		head = head->next;
		val = temp->value;
		delete temp;
		temp = nullptr;
	}
	return val;
}

template<typename T>
T LinkedList<T>::removeatEnd() {
	T val;
	if (isEmpty())
	{
		cout << "\nList is Empty cannot Remove anymore\n";
	}
	else
	{
		Node<T>* temp = head;
		Node<T>* prev = nullptr;
		while (temp->next != nullptr)
		{
			prev = temp;
			temp = temp->next;
		}
		val = temp->value;
		if (temp == head)
		{
			delete temp;
			prev = temp = nullptr;
		}
		else
		{
			prev->next = nullptr;
			delete temp;
		}
	}
	return val;
}

template<typename T>
bool LinkedList<T>::search(T d, int& index)
{
	Node<T>* temp = head;
	if (isEmpty())
	{
		return false;
	}
	else
	{
		while (temp != nullptr)
		{
			if (temp->value == d)
			{
				return true;
			}
			index++;
			temp = temp->next;
		}
		return false;
	}
}

template<typename T>
int LinkedList<T>::ListLength()
{
	int length = 0;
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		length++;
		temp = temp->next;
	}
	return length;
}

template<typename T>
void LinkedList<T>::Revarsal()
{
	if (isEmpty())
	{
		cout << "\nList is Empty cannot Reverse\n";
	}
	else
	{
		int count = ListLength();
		for (int i = 0; i < count - 1; i++)
		{
			insertAt(removeatEnd(), i);
		}
	}

}

template<typename T>
LinkedList<T>& LinkedList<T>::operator+(LinkedList<T>& other)
{
	LinkedList<T> list;
	int length = this->ListLength() + other.ListLength();
	Node<T>* temp = this->head;
	for (int i = 0; i < this->ListLength(); i++)
	{
		list.insertAt(temp->value, i);
		temp = temp->next;
	}
	temp = other.head;
	for (int i = this->ListLength(); i < length; i++)
	{
		list.insertAt(temp->value, i);
		temp = temp->next;
	}

	return list;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& other)
{
	this->head = other.head;
	this->current = other.current;
	return (*this);
}

template<typename T>
LinkedList<T> Merge(Node<T>* h1, Node<T>* h2)
{
	LinkedList<T> list;
	while (h1 != nullptr)
	{
		list.insertatEnd(h1->value);
		h1 = h1->next;
	}
	while (h2 != nullptr)
	{
		list.insertatEnd(h2->value);
		h2 = h2->next;
	}

	return list;
}
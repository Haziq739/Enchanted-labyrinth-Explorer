#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct SNode {
	T value;
	SNode<T>* next;
	SNode(T d) :next(nullptr), value(d) {}
};

template<typename T>
class Stack
{
private:
	SNode<T>* top;
public:
	Stack() :top(nullptr) {}
	int size();
	bool empty();
	T Top();
	void push(T dat);
	T pop();
	//~Stack();
};

template<typename T>
bool Stack<T>::empty() { return top == nullptr; }

template<typename T>
int  Stack<T>::size() {
	int size = 0;
	SNode<T>* temp = top;
	while (temp != nullptr)
	{
		size++;
		temp = temp->next;
	}
	return size;
}


template<typename T>
T Stack<T>::Top() {
	if (empty())
	{
		cout << "\nStack is Empty.\n";
		return T();
	}
	else
	{
		return top->value;
	}
}

template<typename T>
void Stack<T>::push(T dt)
{

	SNode<T>* newNode = new SNode<T>(dt);
	newNode->next = top;
	top = newNode;
}

template<typename T>
T Stack<T>::pop()
{
	if (empty())
	{
		cout << "\nStack is Empty, cannot POP.\n";
		return T();
	}
	else
	{
		T val = top->value;
		SNode<T>* temp = top;
		top = top->next;
		delete temp;
		return val;
	}
}

template<typename T>
Stack<T> Queue(Stack<T>&stack)
{
	Stack<T> queue;
	while (!stack.empty())
	{
		queue.push(stack.pop());
	}
	return queue;

}
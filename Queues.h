#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct QNode {
	T value;
	QNode<T>* next;
	QNode(T d) :next(nullptr), value(d) {}
};

template<typename T>
class Queues
{
private:
	QNode<T>* front;
	QNode<T>* rear;
public:
	Queues() :front(nullptr), rear(nullptr) {}
	T Front();
	T Rear();
	QNode<T>* getFront();
	QNode<T>* getRear();
	int size();
	bool empty();
	void enqueue(T dat);
	T dequeue();
	~Queues();
};

template<typename T>
T Queues<T>::Front() { return front->value; }

template<typename T>
T Queues<T>::Rear() { return rear->value; }

template<typename T>
QNode<T>* Queues<T>::getFront() { return front; }

template<typename T>
QNode<T>* Queues<T>::getRear() { return rear; }

template<typename T>
bool Queues<T>::empty() { return front == nullptr; }


template<typename T>
int Queues<T>::size() {
	int size = 0;
	if (empty())
	{
		return size;
	}
	else
	{
		size = 1;
		QNode<T>* temp = front;
		while (temp != rear)
		{
			size++;
			temp = temp->next;
		}
		return size;
	}
}

template<typename T>
void Queues<T>::enqueue(T dat) {
	QNode<T>* newNode = new QNode<T>(dat);
	if (empty())
	{
		front = newNode;
		rear = front;
	}
	else
	{
		rear->next = newNode;
		rear = rear->next;
	}
}

template<typename T>
T Queues<T>::dequeue() {
	if (empty())
	{
		cout << "\nQueue is Empty, Cannot POP\n";
		return T();
	}
	else
	{
		T val = front->value;
		if (front == rear)
		{
			delete front;
			front = rear = nullptr;
		}
		else
		{
			QNode<T>* temp = front;
			front = front->next;
			delete temp;
			temp = nullptr;
		}
		return val;
	}
}

template<typename T>
Queues<T>::~Queues()
{
	//while (front != nullptr)
	//{
	//	dequeue();
	//}
	//front = rear = nullptr;
}

template<typename T>
Queues<T> Stacks(Queues<T>& queue)
{
	Queues<T> Stack;
	int size = queue.size();
	while (Stack.size() != size)
	{
		int count = queue.size();
		for (int i = 0; i < count - 1; i++)
		{
			T val = queue.dequeue();
			queue.enqueue(val);
		}
		Stack.enqueue(queue.dequeue());
	}
	return Stack;
}
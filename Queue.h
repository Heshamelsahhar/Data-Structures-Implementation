#pragma once
#include <iostream>

using namespace std;
template <typename T>


class QueueH {
private:
	struct Node {
		Node* next;
		T Value;
	};
	int size;
	Node* head;
	Node* tail;

public:	
	QueueH();
	~QueueH();
	void Enqueue(const T& Val);
	T Dequeue();
	bool Empty();



};

template <typename T>
QueueH<T>::QueueH():size(0) {
	head = nullptr;
	tail = nullptr;
}

template <typename T>
QueueH<T>::~QueueH() {
	Node* curr = head;
	Node* temp;
	while (curr != NULL) {
		temp = curr->next;
		delete curr;
		curr = temp;
	}
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
void QueueH<T>::Enqueue(const T& val) {
	Node* newNode = new Node;
	newNode->Value = val;
	if (head == nullptr) {
		head = newNode;
		tail = head;
		head->next = nullptr;
	}
	else if (head != nullptr)
	{
		tail->next = newNode;
		tail = newNode;
	}

	size++;

}

template <typename T>
T QueueH<T>::Dequeue() {
	if (size <= 0) throw("Queue is empty");
	if (size == 1)
	{
		
		T ret = head->Value;
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
		return ret;
	}
	else {
		Node* temp = head;
		T ret = head->Value;
		head = head->next;
		delete temp;
		size--;
		return ret;
	}
}
template <typename T>
bool QueueH<T>::Empty() {
	return size == 0;
}
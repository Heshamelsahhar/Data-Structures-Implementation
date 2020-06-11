#pragma once
#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
private:
	struct Node
	{
		Node* next;
		T data;
	};
	int size;
	Node* head;

public:

	LinkedList();
	~LinkedList();
	void insert(int index, const T& data);
	T get(int index);
	void erase(int index);
	int Length();
	bool empty();
	void Push_front(const T& val);
	void Push_back(const T& val);

};

template <typename T>
LinkedList<T>::LinkedList(){
	size = 0;
	head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList(){

	Node* curr = head;
	while (curr != nullptr) {
		Node* Next = curr->next;
		delete curr;
		curr = Next;
	}
	head = nullptr;
}

template <typename T>
void LinkedList<T>::insert(int index, const T& data) {
	
	if (index < 0 || index > size) throw("Index out of bounds");

	if (index == 0)
	{
		Node* NewHead = new Node;
		NewHead->next = head;
		NewHead->data = data;
		head = NewHead;
	}
	else {
		Node* curr = head;
		Node* prev = nullptr;
		int i = 0;
		for (; curr != nullptr; curr = curr->next, i++)
		{
			if (i == index - 1) prev = curr;
			if (i == index) break;
		}
		Node* NewNode = new Node;
		NewNode->next = curr;
		NewNode->data = data;
		prev->next = NewNode;
	}
	size++;

}
template <typename T>
T LinkedList<T>::get(int index) {
	Node* curr = head;
	int i = 0;
	for (; curr != nullptr; curr = curr->next, i++)
	{
		if (i == index) break;
	}

	return curr->data;
}

template <typename T>
void LinkedList<T>::erase(int index) {

	if (index < 0 || index >= size) throw("Index out of bounds");
	if (index == 0)
	{
		Node* NewNode = head;
		head = head->next;
		delete NewNode;
	}
	else {
		Node* curr = head;
		Node* prev = nullptr;
		int i = 0;
		for (; curr != nullptr; curr = curr->next, i++)
		{
			if (i == index - 1) prev = curr;
			if (i == index) break;
		}
		prev->next = curr->next;
		delete curr;
	}
	size--;

}

template <typename T>
int LinkedList<T>::Length() {
	return size;
}

template <typename T>
bool LinkedList<T>::empty() {
	return size == 0;
}

template <typename T>
void LinkedList<T>::Push_front(const T& val) {
	insert(0, val);
}

template <typename T>
void LinkedList<T>::Push_back(const T& val) {
	insert(size, val);
}
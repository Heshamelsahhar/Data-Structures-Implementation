#pragma once

#include <iostream>
#include <string>

template <typename T>
class VectorH
{

	private:
		int size;
		int capacity;
		T* arr;
	public:
		VectorH();
		VectorH(const VectorH<T>& copyVector);

		~VectorH();

		void push(const T& value);
		void erase(const int idx);
		void insert(const int idx, const T& value);
		T get(int idx);
		VectorH<T>& operator= (const VectorH<T>& copy);
		T& operator[](const int& idx) const;
		int length();
		void clear();
};


template <typename T>
VectorH<T>::VectorH() : size(0), capacity(0), arr(nullptr) {

}

template <typename T>
VectorH<T>::VectorH(const VectorH<T>& copyVec) : size(0), capacity(0), arr(nullptr) {

	*this = copyVec;
}

template<typename T>
VectorH<T>::~VectorH()
{
	this->clear();
}

template <typename T>
void VectorH<T>::push(const T& elem) {

	if (capacity > size) arr[size] = elem, size++;
	else {

		if (capacity == 0)
		{
			capacity = 2;
		}
		else {
			capacity *= 2;
		}

		T* newArr = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		newArr[size++] = elem;

		if (arr != nullptr) delete[] arr;
		arr = newArr;

	}

}

template <typename T>
void VectorH<T>::erase(const int idx) {
	if (idx >= 0 && idx < size) {
		for (int i = idx; i + 1 < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		size--;
	}

}

template <typename T>
void VectorH<T>::insert(const int idx, const T& value)
{
	if (idx >= 0 && idx < size)
	{
		if (size >= capacity)
		{
			if (capacity == 0) capacity = 2;
			else capacity = capacity * 2;

			T* newArr = new T[capacity];
			for (int i = 0; i < idx; i++)
			{
				newArr[i] = arr[i];
			}
			newArr[idx] = value;
			for (int i = idx + 1; i <= size; i++)
			{
				newArr[i] = arr[i - 1];
			}
			if (arr != nullptr)
				delete[] arr;
			
			arr = newArr;
			size++;
		}
		else {
		
			for (int i = size; i > idx; i--)
			{
				arr[i] = arr[i - 1];
			}
			arr[idx] = value;
			size++;

		}
	}
	else if (idx >= 0 && size == idx)
	{
		this->push(value);
	}
}

template <typename T>
T VectorH<T>::get(int idx)
{
	return arr[idx];
}

template<typename T>
int VectorH<T>::length()
{
	return this->size;
}

template<typename T>
T& VectorH<T>::operator[](const int& idx)const{

	if (!(idx >= 0 && idx < size)) throw ("Error: index out of bounds");
	return arr[idx];
}
template <typename T>
VectorH<T>& VectorH<T>::operator= (const VectorH<T>& copy) {

	if (this != &copy)
	{
		size = copy.size;
		capacity = copy.capacity;
		arr = new T[capacity];
		if (arr == nullptr) throw("Failed allocating memory for array");
		memcpy(arr, copy.arr, size * sizeof(T));

	}

	return *this;
}

template <typename T>
void VectorH<T>::clear() {
	if (capacity > 0) delete[] arr;
	size = 0;
	capacity = 0;
	arr = nullptr;
}
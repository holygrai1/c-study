#pragma once
#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack &s);
	//~Stack();
	bool empty() const;
	void pop();
	void push(const T& s);
	int get_size() const;
	T top() const;
private:
	vector<T> array;
	int size;
};

template <typename T>
Stack<T>::Stack() {
	size = 0;
}
//template <typename T>
//Stack<T>::~Stack() {
//	cout << "null" << endl;
//}
template <typename T>
Stack<T>::Stack(const Stack& s) {
	size = 0;
	for (int i = 0; i < s.size; i++) {
		array.push_back(s.array[i]);
		size++;
	}
}
template <typename T>
bool Stack<T>::empty() const {
	return array.empty();
}

template <typename T>
void Stack<T>::pop() {
	if (size == 0) {
		cout << "нч" << endl;
		return;
	}
	array.pop_back();
	size -= 1;
}

template <typename T>
void Stack<T>::push(const T& s) {
	array.push_back(s);
	size += 1;
}

template <typename T>
int Stack<T>::get_size() const {
	return size;
}
template <typename T>
T Stack<T>::top() const {
	if (array.empty()) {
		return T();
	}
		return array.back();
}

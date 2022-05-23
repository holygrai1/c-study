#pragma once
#include "Stack.h"
template<typename T>
class Queue
{
public:
	Queue();
	//~Queue();
	bool empty() const;
	T pop_back();
	T pop_front();
	void push_back(T s);
	void push_front(T s);
	int get_size( ) const;
private:
	Stack<T>s1, s2;
	int size;
};


template<typename T>
Queue<T>::Queue()
{
	size = s1.get_size() + s2.get_size();
}
//template<typename T>
//Queue<T>::~Queue()
//{
//}

template<typename T>
bool Queue<T>::empty() const
{
	return s1.empty() && s2.empty();
}

template<typename T>
void Queue<T>::push_back(T s)
{
	s1.push(s);
}
template<typename T>
void Queue<T>::push_front(T s)
{
		s2.push(s);
}


template<typename T>
T Queue<T>::pop_front()
{
	T num;
	if (!s2.empty()) {
		num = s2.top();
		s2.pop();
		return num;
	}
	while (!s1.empty())
	{
		T temp;
		temp = s1.top();
		s1.pop();
		s2.push(temp);
	}
	num = s2.top();
	s2.pop();
	return num;
}

template<typename T>
T Queue<T>::pop_back()
{
	T num;
	if (!s1.empty()) {
		num = s1.top();
		s1.pop();
		return num;
	}
	while (!s2.empty())
	{
		T temp;
		temp = s2.top();
		s2.pop();
		s1.push(temp);
	}
	num = s1.top();
	s1.pop();
	return num;
}

template<typename T>
int Queue<T>::get_size() const
{
	return s1.get_size() + s2.get_size();
}
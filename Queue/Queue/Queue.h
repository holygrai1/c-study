#pragma once
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class MyCircularQueue
{
private:
	int maxsize;
	int size;
	T *arr;
	int font;
	int rear;
public:
	MyCircularQueue(int s);//���ö��г���
	//MyCircularQueue(const MyCircularQueue& s);
	//MyCircularQueue(const T& s);
	~MyCircularQueue();
	T Front() const;//���׵�Ԫ�أ�û��Ϊ-1
	T Rear() const;//��β��Ԫ�أ�û��Ϊ-1
	bool enQueue(const T&s);//��β����Ԫ��,���ҷ���Ϊtrue
	bool deQueue();//����ɾ��Ԫ�أ�����true
	bool isEmpty() const;//���ж�
	bool isFull() const;//���ж�
	int get_size()const;
} ;

template<typename T>
MyCircularQueue<T>::MyCircularQueue(int s) {
	maxsize = s + 1;
	arr = new T[maxsize];
	size = 0;
	font = 0;
	rear = 0;
}

//template<typename T>
//MyCircularQueue<T>::MyCircularQueue(const T* s) {
//	font = 0;
//	
//	/*size = sizeof(s) / sizeof(s[0]);*/
//	maxsize = size + 1;
//	rear = maxsize;
//}

//template<typename T>
//MyCircularQueue<T>::MyCircularQueue(const MyCircularQueue& s){
//	maxsize = s.maxsize
//	size = s.size;
//	
//	font = s.font;
//	rear = s.rear;
//}


template<typename T>
 MyCircularQueue<T>::~MyCircularQueue() {
	 delete[ ] arr;
}
template<typename T>
T MyCircularQueue<T>::Front() const {
	cout << size << endl;
	cout << font << endl;
	cout << rear << endl;
	return arr[font];
}
template<typename T>
T MyCircularQueue<T>::Rear() const {
	if(!this->isEmpty()){
	if (rear - 1 !=  -1) {
		return arr[rear - 1];
	}
	else {
		return arr[maxsize - 1];
	}
	}
	else {
		return T();
	}
}
template<typename T>
bool MyCircularQueue<T>::enQueue(const T& s) {
	if (!this->isFull()) {
		arr[rear] = s;
		rear = (rear + 1) % maxsize;
		size += 1;
		cout << font <<"font" << endl;
		cout << rear << "rear" << endl;
		cout << size << "size" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
template<typename T>
bool MyCircularQueue<T>::deQueue() {
	if (!this->isEmpty()) {
		arr[font].~T();
		font = (font + 1) % maxsize;
		size -= 1;
		cout << font << "font" << endl;
		cout << rear << "rear" << endl;
		cout << size << "size" << endl;
		return true;
	}
	else
	{
		return false;
	}
}
template<typename T>
bool MyCircularQueue<T>::isEmpty() const {
	if (font == rear) {
		return true;
	}
	else
	{
		return false;
	}

}
template<typename T>
bool MyCircularQueue<T>::isFull() const {
	int temp = (rear + 1) % maxsize;
	if (temp == font) {
		return true;
	}
	else
	{
		return false;
	}
}
template<typename T>
int  MyCircularQueue<T>::get_size()const {
	return size;
}


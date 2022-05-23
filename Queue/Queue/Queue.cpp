#include "Queue.h"
int main() {
	int test[3] = { 1,2,3 };
	MyCircularQueue <int> test1(3);
	test1.enQueue(1);
	test1.enQueue(2);
	test1.enQueue(3);
	test1.deQueue();
	test1.enQueue(4);
	cout << test1.isEmpty() << endl;
	cout << test1.isFull() << endl;
	return 0;
}
#include "Stack.h"
#include "Queue.h"
int main() {
	/*Stack<int> intStack;
	Stack<char> charStack;
	intStack.push(1);
	intStack.push(2);
	charStack.push('s');
	cout << intStack.top() << endl;
	cout << charStack.top() << endl;*/
	Queue<int> intStack;
	intStack.push_back(2);
	intStack.push_back(3);
	intStack.push_front(1);
	cout << intStack.pop_front() << endl;
	cout << intStack.pop_back() << endl;
	return 0;
}
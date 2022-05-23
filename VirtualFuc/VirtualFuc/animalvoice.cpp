
#include "cat.h"
#include "dog.h"
using namespace std;
int main() {
	Animal* cat = new Cat;
	cat->voice();
	Animal* dog = new Dog;
	dog->voice();
};
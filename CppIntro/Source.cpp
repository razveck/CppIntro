//C
#include <stdio.h>
//C++
#include <iostream>

#include "Header.h"

#define Square(a) a*a
#define PI 3.14

typedef int SIZE;

using namespace std;

int SquareFunc(int a) {
	return a * a;
}

void main() {
	SIZE number = 10;
	float radius = PI * 2;
	char letter= 'a';
	
	int threeSquared = Square(3);
	cout << threeSquared << endl;

	int fourSquared = SquareFunc(4);
	cout << fourSquared << endl;
	PrintName();

	//C# local vars go on the stack
	//class instances (and all members) go on the heap

	//C++ we can choose where everything goes
	//On the stack
	Mug bob = Mug();
	bob.Content = 999;

	//On the heap
	Mug* mary = new Mug();

	//dereferencing the pointer
	(*mary).Content = 64;

	mary->Content = 32;

	cout << (*mary).Content << endl;
	cout << mary->Content << endl;

	Mug* coffee = mary;
	cout << coffee->Content << endl;

	//address of bob
	coffee = &bob;


	//C heap allocation - it doesn't support classes nor constructors
	Mug* tea = (Mug*)malloc(sizeof(Mug));
	//C deallocation
	free(tea);

	//C++ heap allocation
	Mug* milk = new Mug();
	//C++ deallocation
	delete milk;
}

//definition or implementation
void PrintName() {
	//C
	printf("Joao with printf\n");
	//C++
	cout << "Joao" << endl;
}

void Foo() {

}
//C
#include <stdio.h>
//C++
#include <iostream>
#include <array>
#include <vector>
#include <string>

#include "Header.h"

#define Square(a) a*a
#define PI 3.14

typedef int SIZE;

//using namespace std;

int SquareFunc(int a) {
	return a * a;
}

void main() {
	SIZE number = 10;
	float radius = PI * 2;
	char letter= 'a';
	
	int threeSquared = Square(3);
	std::cout << threeSquared << std::endl;

	int fourSquared = SquareFunc(4);
	std::cout << fourSquared << std::endl;
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

	std::cout << (*mary).Content << std::endl;
	std::cout << mary->Content << std::endl;

	Mug* coffee = mary;
	std::cout << coffee->Content << std::endl;

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

	//C# null
	//C
	Mug* mug1 = NULL;
	//C++
	mug1 = nullptr;

	//smart pointers
	//CreateLotsOfGarbage();
	CreateLotsOfGarbageSmartPtr();

	//C# delegate
	//delegate void PrintDelegate ();
	//PrintDelegate print;
	//declaring a pointer to a function that takes no parameters and returns void
	void (*print) ();
	print = PrintName;
	print();
	Foo(print);

	//declaring a pointer to a function that takes an int parameter and returns an int
	int (*intFunc)(int a);
	intFunc = SquareFunc;
	intFunc(2);


	//C#
	//int[] numbers;
	//numbers.Length
	//numbers.blablabla
	//C
	//int numbers[] = {1,5,7,8,4};
	const int numbersLength = 10;
	int numbers[numbersLength];
	numbers[0] = 77;
	*numbers = 76;
	numbers[3] = 137412;
	*(numbers + 3) = 1000;
	int index4 = numbers[4];
	std::cout << "For loop" << std::endl;

	for (size_t i = 0; i < numbersLength; i++)
	{
		std::cout << numbers[i] << std::endl;
	}

	//C# foreach
	//foreach(int i in numbers)
	//C++ range-based for loop
	std::cout << "Ranged for loop" << std::endl;
	for (int i : numbers) {
		std::cout << i << std::endl;

	}

	//foreach(var i in numbers)
	std::cout << "Ranged for loop with auto" << std::endl;

	for (auto i : numbers)
	{
		std::cout << i << std::endl;
	}

	//C# array
	std::array<int, 3> numbersArray = { 5, 8, 19 };
	numbersArray[1] = 372649146239;
	std::cout << "std::array" << std::endl;
	for (size_t i = 0; i < numbersArray.size(); i++)
	{
		std::cout << numbersArray[i] << std::endl;
	}
	
	//C# List
	std::vector<int> numbersVector = { 2,6,4,3 };
	std::cout << "std::vector" << std::endl;
	for (size_t i = 0; i < 500; i++)
	{
		//std::cout << numbersVector[i] << std::endl;
		//C# List.Add
		numbersVector.push_back(i);
	}
	
	//C#
	//string f = "hhh";
	//C-style string
	char greeting[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	const char* greeting2 = "Hello";
	//C++
	std::string name = "joao";
	
	Person p1 = Person();
	p1.Name = "Bob";
	p1.Age = 70;
	

	
	Person* p2 = new Person("Jenny");
	PrintAPerson(p2);

	delete p2;

	GameDev dev = GameDev();
	dev.Name = "ff";
	PrintAPerson(&dev);

	//cannot instantiate abstract class
	//Musician m = Musician();

	MusicTeacher teacher = MusicTeacher();
	
	Musician* m;
	m = &teacher;
	m->PlayInstrument();
}

void PrintAPerson(Person* person) {
	person->Print();
}

void CreateLotsOfGarbage() {
	for (size_t i = 0; i < 1000; i++)
	{
		Mug* mug = new Mug();
	}
}

void CreateLotsOfGarbageSmartPtr() {
	for (size_t i = 0; i < 1000; i++)
	{
		//similar to the normal C# reference
		std::shared_ptr<Mug> sharedMug( new Mug());
		
		//there can only ever be one unique ptr pointing at each memory location. Can't be copied
		std::unique_ptr<Mug> uniqueMug(new Mug());

		//compile error: can't copy unique_ptr
		//std::unique_ptr<Mug> mug2 = uniqueMug;

	}
}

//definition or implementation
void PrintName() {
	//C
	printf("Joao with printf\n");
	//C++
	std::cout << "Joao" << std::endl;
}

//C#
//void Foo(PrintDelegate func) {
//	func();
//}

void Foo(void (*func)()) {
	func();
}

//definition of a function declared in a class
void MusicTeacher::PrintInstrument() {

}
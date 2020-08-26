#pragma once
#include <string>
#include <iostream>

//declaration
void PrintName();
void Foo(void (*func)());
void CreateLotsOfGarbage();
void CreateLotsOfGarbageSmartPtr();


struct Mug {
	//defaults to public
	int Content;
};

class Person {
	//defaults to private
private:
	Mug _favoriteMug = Mug();
	Person* _mother = nullptr;

public:
	std::string Name = "";
	int Age = 0;

	void Foo() {
		_favoriteMug.Content = 10;
		//_mother = new Person();
	}

	Person() {
		std::cout << "Default constructor" << std::endl;
	}

	Person(std::string name) {
		std::cout << "Overloaded constructor" << std::endl;
		Name = name;
	}

	~Person() {
		std::cout << "DESTROYED" << std::endl;

		delete _mother;
	}

	Mug GetFavoriteMug() const {
		return _favoriteMug;
	}

	void SetFavoriteMug(Mug mug) {
		_favoriteMug = mug;
	}

	virtual void Print() {
		std::cout << "This is Person" << std::endl;
	}

protected:
	int Salary;
};

class GameDev : public Person {
private:
	void Foo() {
		Salary = 200;
	}

public:
	void Print() {
		std::cout << "This is game dev" << std::endl;
	}
};

class GameDesigner : public GameDev {

};

//C# abstract class
class Musician {
public:
	//C# abstract method
	virtual void PlayInstrument() = 0;
};

class MusicTeacher : public Person, public Musician {
public:
	virtual void PlayInstrument() {
		std::cout << "Playing beautiful music" << std::endl;
	}

	//declaration inside of class
	void PrintInstrument();
};

void PrintAPerson(Person* person);
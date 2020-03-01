#include "Farm.h"
#include "Dog.h"
#include "Cow.h"
#include <time.h>

Farm::Farm(int size) : _size(size)
{

	generateAnimals();

}

void Farm::generateAnimals()
{

	srand(time(NULL));

	for (int i = 0; i < _size; i++)
	{

		_animals.push_back(rand() % 2 == 0 ? static_cast<Animal*>(new Dog) : static_cast<Animal*>(new Cow));
	
	}

}

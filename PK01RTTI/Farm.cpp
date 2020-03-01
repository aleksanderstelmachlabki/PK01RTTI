#include "Farm.h"
#include "Dog.h"
#include "Cow.h"
#include <time.h>
#include "CustomCastService.cpp"
#include <chrono>

Farm::Farm(int size) : _size(size)
{

	generateAnimals();

}

void Farm::makeSomeNoise(Animal* animal)
{

	if (animal != nullptr)
	{

		if (Dog* dog = dynamic_cast<Dog*>(animal))
		{

			dog->bark();

		}
		else if (Cow* cow = dynamic_cast<Cow*>(animal))
		{

			cow->moo();

		}
		else
		{

			animal->sayHello();

		}

	}

}

void Farm::makeSomeNoiseVeryInelegant(Animal* animal, AnimalSpecies species)
{

	if (animal != nullptr)
	{

		switch (species)
		{

		case AnimalSpecies::Cows:

			static_cast<Cow*>(animal)->moo();

			break;

		case AnimalSpecies::Dogs:

			static_cast<Dog*>(animal)->bark();

			break;

		default:

			animal->sayHello();

			break;

		}

	}

}

void Farm::generateAnimals()
{

	srand(time(NULL));

	for (int i = 0; i < _size; i++)
	{

		_animals.push_back(rand() % 2 == 0 ? static_cast<Animal*>(new Dog) : static_cast<Animal*>(new Cow));

	}

}

std::vector<Dog*> Farm::transformAnimalsToDogsWithCustomCast(std::vector<Animal*> animals)
{

	std::vector<Dog*> dogs;

	for (int i = 0; i < animals.size(); i++)
	{

		dogs.push_back(CustomCastService::custom_dynamic_cast<Dog>(animals[i]));

	}

	return dogs;

}

std::vector<Dog*> Farm::transformAnimalsToDogsWithDynamicCast(std::vector<Animal*> animals)
{

	std::vector<Dog*> dogs;

	for (int i = 0; i < animals.size(); i++)
	{

		dogs.push_back(dynamic_cast<Dog*>(animals[i]));

	}

	return dogs;

}

int Farm::countCows() const
{

	int count = 0;

	for (int i = 0; i < _size; i++)
	{

		if (dynamic_cast<Cow*>(_animals[i]))
		{

			count++;

		}

	}

	return count;

}

void Farm::testCastTime()
{

	std::vector<Animal*> animals;

	for (int i = 0; i < 10000000; i++)
	{

		animals.push_back(new Dog);

	}

	auto dynamicCastTestStartTimeStamp = std::chrono::steady_clock::now();

	transformAnimalsToDogsWithDynamicCast(animals);

	auto dynamicCastTestStopTimeStamp = std::chrono::steady_clock::now();

	auto customCastTestStartTimeStamp = std::chrono::steady_clock::now();

	transformAnimalsToDogsWithCustomCast(animals);

	auto customCastTestStopTimeStamp = std::chrono::steady_clock::now();

	std::cout << "Dynamic cast: " << std::chrono::duration_cast<std::chrono::milliseconds>(dynamicCastTestStopTimeStamp - dynamicCastTestStartTimeStamp).count() << std::endl;
	std::cout << "Custom cast: " << std::chrono::duration_cast<std::chrono::milliseconds>(customCastTestStopTimeStamp - customCastTestStartTimeStamp).count() << std::endl;

}

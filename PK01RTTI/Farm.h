#ifndef FARM_H_
#define FARM_H_
#include "Animal.h"
#include "AnimalSpecies.h"
#include "Dog.h"
#include <vector>

class Farm
{

private:

	int _size = 0;
	std::vector<Animal*> _animals;

public:

	Farm(int size);

	void makeSomeNoise(Animal* animal);
	void makeSomeNoiseVeryInelegant(Animal* animal, AnimalSpecies species);
	int countCows() const;
	int countDogs() const { return _size - countCows(); }
	void testCastTime();

private:

	void generateAnimals();
	std::vector<Dog*> transformAnimalsToDogsWithCustomCast(std::vector<Animal*> animals);
	std::vector<Dog*> transformAnimalsToDogsWithDynamicCast(std::vector<Animal*> animals);

};

#endif

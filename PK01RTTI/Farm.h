#ifndef FARM_H_
#define FARM_H_
#include "Animal.h"
#include "Dog.h"
#include <vector>

class Farm
{

private:

	int _size = 0;
	std::vector<Animal*> _animals;

public:

	Farm(int size);

private:

	void generateAnimals();

};

#endif

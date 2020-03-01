#ifndef COW_H_
#define COW_H_
#include "Animal.h"
#include <iostream>

class Cow : public Animal
{

public:

	virtual ~Cow() {};

	inline void moo() const { std::cout << "Moooooooo!" << std::endl; };

};

#endif

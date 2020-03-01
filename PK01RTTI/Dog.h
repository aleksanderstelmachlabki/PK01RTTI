#ifndef DOG_H_
#define DOG_H_
#include "Animal.h"
#include <iostream>
#include <string>

class Dog : public Animal
{

	const std::string BARK_TEXT = "Woof woof";
	
public:

	virtual ~Dog() {};

	inline void bark() const { std::cout << BARK_TEXT << std::endl; };

};

#endif

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>

class Animal
{

public:


	virtual ~Animal() {};

	inline void sayHello() const { std::cout << "*Random sound*" << std::endl; };

};

#endif

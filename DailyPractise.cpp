#include <iostream>
#include <string>
#include <map>
#include <list>
#include <random>
#include "destructorFunction.h"




int main()
{
	A* a = new B(5, 10);

	//a->~B();
	delete a;
	return 0;
}
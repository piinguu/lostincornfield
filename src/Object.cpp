#include "Object.h"
#include "iostream"

namespace licf {
	Object::Object() : w(0), v(0) {
		std::cout << "Skapar ett objekt med defaultvärden\n";
	}

	Object::Object(double weight, double volume) : w(weight), v(volume) 
	{
		std::cout << "Skapar ett objekt med vikten " << weight << " och volymen " << volume << "\n";
	}
}
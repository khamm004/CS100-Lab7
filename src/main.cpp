#include "../header/factory.hpp"
#include <iostream>
#include "../header/base.hpp"



int main(int argc, char** argv){
	
	Factory* f =new Factory();
	Base* output = f->parse(argv, argc);
	if (output == nullptr){
		std::cout << "Invalid Input!!" << endl;
	}
	else{
		std::cout << output->stringify() << endl;
		std::cout << output->evaluate() << endl;
	}
	return 0;
}


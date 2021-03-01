#ifndef __POW_HPP__
#define __POW_HPP__

#include <cmath>
#include "base.hpp"

using namespace std;

class Pow : public Base {
	private:
		Base* left;
		Base* right;
	public: 
		Pow();
		Pow(Base* lh, Base* rh) {left =lh; right=rh;}
		double evaluate(){return pow(left->evaluate(), right->evaluate());}
		string stringify() {return "(" + left->stringify() + "**" + right->stringify() + ")";}
};
#endif 

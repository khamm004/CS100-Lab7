#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

using namespace std;

class Add : public Base {
	private: 
		Base* left;
		Base* right;
	public:
		Add();
		Add(Base* lh, Base* rh){left=lh; right=rh;};
		double evaluate(){return left->evaluate()+right->evaluate();}
		string stringify() {return "(" + left->stringify() + "+" + right->stringify() + ")";}
};
#endif

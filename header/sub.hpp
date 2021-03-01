#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

using namespace std;

class Sub : public Base {
	private: 
		Base* left;
		Base* right;
	public:
		Sub();
		Sub(Base* lh, Base* rh){left=lh; right=rh;}
		double evaluate(){return left->evaluate()-right->evaluate();}
		string stringify() {return "(" + left->stringify() + "-" + right->stringify() + ")";}
};
#endif

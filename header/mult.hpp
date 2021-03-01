#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    private:
        Base* left;
	Base* right;
    public:
        Mult(Base* lt, Base* rt) : Base() {left = lt; right = rt;}

        virtual double evaluate() { return (left->evaluate())*(right->evaluate()); }
        virtual std::string stringify() { return '(' + left->stringify() + '*' + right->stringify() + ')'; }
};

#endif //__MULT_HPP__


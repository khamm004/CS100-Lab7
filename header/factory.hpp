#include <iostream>
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "base.hpp"
#include <cstring>
class Base;

class Factory{

public:
	Factory(){};
	~Factory(){};
	Base* parse(char** input, int length){
		int op_length = length/2;
		int num = 0;
		int count1 = 0;
		int count2 = 0;
		int operand[op_length+1];
		std::string operatr[op_length];		

		for(int i=1;i<length;i++){ 
			if (isdigit(input[i][0])){
				for(int k=0;k<strlen(input[i]);k++){
					num+= ((int)input[i][k]-48)*pow(10,(strlen(input[i]) - 1 - k));
				}
				operand[count1]=num;
				count1++;
				num = 0;
			}
			else if (input[i] == "+" ||input[i]=="-" || input[i]=="/" || input[i]== "*" ||input[i]=="**"){
				operatr[count2]=input[i];
				count2++;
			}
			else{
				std::cout<< "invalid input!";
				return nullptr;
			}
		}
		std:: string sign;
		Base* temp1;
		Base* temp2;
		Base* temp3;
		Base* temp4;
		temp1 = new Op(operand[0]);
		temp2 = new Op(operand[1]);
		sign = operatr[0];
		
		if (sign=="+"){
			temp3 = new Add(temp1, temp2);		
		}
		else if (sign=="-"){
			temp3= new Sub(temp1, temp2);
		}
		else if (sign=="/"){
			temp3= new Div(temp1, temp2);
		}
		else if (sign=="*"){
			temp3= new Mult(temp1, temp2);
		}
		else if (sign=="**"){
			temp3= new Pow(temp1, temp2);
		}
		delete temp1;
		int count = 2;
		for(int i = 1; i<op_length; i++){		
			delete temp2;
			temp2 = new Op(operand[count]);
			sign=operatr[i];
			if (sign=="+"){
				temp4 = new Add(temp3, temp2);
			
			}
			else if (sign=="-"){
				temp4 = new Sub(temp3, temp2);
			}
			else if (sign=="/"){
				temp4 = new Div(temp3, temp2);
			}
			else if (sign=="*"){
				temp4 = new Mult(temp3, temp2);
				
			}
			else if (sign=="**"){
				temp4 = new Pow(temp3, temp2);
			}
			count++;
		}
		delete temp2;
		delete temp3;
		return temp4;
	}
};	



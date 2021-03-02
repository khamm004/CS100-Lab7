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
	Base* parse(char** input, int length){
		if (length%2==1){
			return nullptr;
		}
		int op_length = (length-1)/2;
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
            		else if (input[i][0] == '+' ||input[i][0]=='-' || input[i][0]=='/' || input[i][0]== '*' || (input[i][0]=='*' && input[i][1]=='*')){
                		operatr[count2]=input[i];
                		count2++;
            		}
            		else{;
                		return nullptr;
            		}
        	}

        	Base* temp1;
        	Base* temp2;
        	Base* temp3;
		if ((length == 2 && (!isdigit(input[1][0]))) || (!isdigit(input[1][0]))){
			return nullptr;
		}
        	temp1 = new Op(operand[0]);
		if (length ==2){
			return temp1;
		}
        	temp2 = new Op(operand[1]);
        
        	if (operatr[0][0]=='+'){
			temp3 = new Add(temp1, temp2);      
		}
        	else if (operatr[0][0]=='-'){
			temp3= new Sub(temp1, temp2);
		}
		else if (operatr[0][0] =='/'){
			temp3= new Div(temp1, temp2);
		}
		else if (operatr[0][0]=='*' && operatr[0][1]=='*'){
                        temp3= new Pow(temp1, temp2);
                }
		else if (operatr[0][0]=='*'){
			temp3= new Mult(temp1, temp2);
		}
		if (op_length==1){
			return temp3;
		}
        	int count = 2;
        	for(int i = 1; i<op_length; i++){       
           		temp2 = new Op(operand[count]);
            		if (operatr[i][0]=='+'){
                		temp1 = new Add(temp3, temp2);
            
   			}
            		else if (operatr[i][0]=='-'){
                		temp1 = new Sub(temp3, temp2);
            		}		
     		       else if (operatr[i][0]=='/'){
                		temp1 = new Div(temp3, temp2);
            		}
			else if (operatr[i][0]=='*' && operatr[i][1]=='*'){
                                temp1 = new Pow(temp3, temp2);
                        }
            		else if (operatr[i][0]=='*'){
                		temp1 = new Mult(temp3, temp2);
                
            		}	
            		count++;
			temp3 = temp1;
        	}
        	return temp1;

/*
		Base* temp = new Op(7);
		Base* temp1 = new Op(8);
		Base* temp2 = new Op(3);	
		Base* mult = new Mult(temp, temp1);
		Base* add = new Add(mult, temp2);
		return add;
*/
	}
};	


#include <iostream>

#include "PrefixToPostfix.h"
using namespace std;


int main() 

{   //Displays all the process of conversion of prefix to postfix expression
    try{
        std::cout<<std::endl;
        string pre_exp = "++12 25";
        std::cout<<"PREFIX OF :   "<<pre_exp<<endl<<std::endl; 
        std::cout<<"Reading the string from right to left order...."<<std::endl;
        std::cout<< PrefixToPostfix(pre_exp)<<std::endl;
        std::cout<<std::endl;
    }
    catch(const char *message){
        std::cerr<<message<<std::endl;   //cerr is standard error stream(for output the errors)(object of class ostream)
    }
}
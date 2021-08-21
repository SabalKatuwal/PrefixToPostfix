
#include <iostream>

#include "PrefixToPostfix.h"
using namespace std;


int main()  
{   //Displays all the process of conversion of prefix to postfix expression
    std::cout<<std::endl;
    string pre_exp = "+++A*BCD";
    std::cout<<"PREFIX OF :   "<<pre_exp<<endl<<std::endl; 
    std::cout<<"Reading the string from right to left order...."<<std::endl;
    std::cout<< PrefixToPostfix(pre_exp)<<std::endl;
    std::cout<<std::endl;


    return 0;
}


catch(const char *error){
    std::cerr<<error<<std::endl;
}  
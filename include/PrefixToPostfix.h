#include <iostream>
using namespace std; 
  
//Class for stack data structure 
class Stack  
{  
    public: 
    int top;  
    unsigned size;  
    string* array;  
};  

//Creates a stack of desired size
Stack* createStack(unsigned size)  
{  
    Stack* stack = new Stack(); 
    stack->size = size;  
    stack->top = -1;  
    stack->array = new string[(stack->size * sizeof(string))];  
    return stack;  
}  

//returns top of stack -1 if it is empty
int isEmpty(Stack* stack)  
{ return stack->top == -1; }   

//check if the stack is full or not  
int isFull(Stack* stack)  
{ return stack->top == stack->size - 1; }  
   
  
//add string to stack and increase the top by 1 
void push(Stack* stack, string stuff)  
{  
    if (!isFull(stack))
    {  
        stack->array[++stack->top] = stuff;
        cout<<stuff <<" is pushed into stack"<<endl;
    }
    else{
        cout<<"Warning:Stack OverFlow"<<endl;
    }
}  
 
//remove stuff from stack and decrease top index by 1  
string pop(Stack* stack)  
{  
    if (!isEmpty(stack)){ 
        string a = stack->array[stack->top--];   
        return a;
        cout<<a <<"is popped from stack"<<endl;
    }
    else{
        cout<<"stack underflow"<<endl;
        return 0;
    }
}  

//returns the item which is at top of stack
string peek(Stack* stack)
{
    if (isEmpty(stack)){
            cout<<"Stack empty."<<endl;
            return 0;
        }   
    else
        {
            return stack->array[stack->top];
        }
}

//checks the character is operator or not 
bool isOperator(char C)
{
    switch (C) {
    case '+':
    case '-':
    case '/':
    case '*':
    case '%':
        return true;
    }
    return false;
}
 
// Convert prefix to Postfix expression
string PrefixToPostfix(string PrefixExp)
{
    // Create stack equal to size of string  
    int length = PrefixExp.size();  
    Stack* stack = createStack(length);
 
    //for loop loops from right to left of string
    for (int i = length - 1; i >= 0; i--)
    {
        if(PrefixExp[i]!= ' ')        //for whitespace removes it 
        {
            // check if symbol is operator
            if (isOperator(PrefixExp[i]))
            {
                // pop two operands from stack
                string op1 = peek(stack);
                pop(stack);
                string op2 = peek(stack);
                pop(stack);
 
                // concat the operands and operator
                string temp = op1 + op2 + PrefixExp[i];
 
                // Push string temp back to stack
                cout<<"As "<<PrefixExp[i]<<" is operator"<<endl;
                push(stack, temp);
            
                cout<<"So stack top is "<<peek(stack)<<endl;
            }      
 
            // if symbol is an operand
            else {
                // push the operand to the stack
                push(stack, string(1, PrefixExp[i]));
            }

        }
    }
    //Display top of stack which is only Postfix Expression 
    cout<<endl;
    cout<<"SO FINAL POSTFIX EXPRESSION IS:  ";
    return peek(stack);
}


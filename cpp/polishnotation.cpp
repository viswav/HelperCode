#include <iostream>
#include <string>
#include <stack>

using namespace std;


//need to change this to work with multiple digits for a char.
string infixTopolish( string infix )
{
    string ret;
    stack<char> opStack;
    
    for( int i=0;i<infix.length();i++)
    {
        char c = infix.charAt(i);
        switch( c ) {
            case '*':
            case '/':
                   if( opStack.top() == '*' || opStack.top() == '/')
                       ret.append(c);
                   else
                       opStack.push(c);
                   break;
            case '+':
            case '_':
                    ret.append(c);                
                    break;
            case ')':
                    while( opStack.top() != ')' ){
                        ret.append(opStack.top());
                        opStack.pop();
                    }
                       break;
            case '(':
                    opStack.push(c);
        }
    }
    
    while( opStack.size() > 0 ){
        char c = opStack.top();
        if( c == '(' || c == ')' ){
            cout << "Syntax error in infix notation.";
            return string("");
            }
        ret.append(c);
        opStack.pop();
    }
    
}


bool evalPolish( vector<string> polish, double val ){
    
    stack<double> numbers;
    for( int i=0;i<polish.size();i++)
    {
        double temp;
        if( temp = strtod(polish[i].c_str(),NULL) ){
            numbers.push(temp);
        }
        else{

         double val1 = numbers.top();
         double val2 = numbers.top();
         
         numbers.pop();
         numbers.pop();

         if( polish[i].equals("*")){
            numbers.push(val1*val2);
         }
         else if( polish[i].equals("/") ) {
             if( val1 == 0.0 ){
                 cout << "Div by zero error"<<endl;//use exception handler
                 return false;
             }
             numbers.push(val2/val1);
         }
         else if( polish[i].equals("-") ) {
             numbers.push(val2-val1);
         }
         else if( polish[i].equals("+") ) {
             numbers.push(val2+val1);
         }
        }
        
    }
    
    val = numbers.top();
    return true;
     
   
}

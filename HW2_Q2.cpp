#include <iostream>  
#include <stack>
using namespace std;

bool isOpr(char c) { //boolean expression that checks if the char passed in is a operand

    return isdigit(c); // isdigit checks if the char passed in is a number and returns to number
}


int main()
{
    string equation;            // declare the string equation
    cout << "write a equation of prefix" << endl;
    cin >> equation;            // takes prefix equation by the user

    stack<int> myStack;     // declare stack name myStack
    int op1, op2;
    for (int i = equation.size() - 1; i >= 0; i--) {     //because prefix needs to calculate the numbers from the top push the number at the top first. 
        if (isOpr(equation[i])) { //checking if the string of the top is number
            myStack.push(equation[i] - '0'); //push the number to the stack, since i is char, by -'0', the i is expressed as a ascii code of number. 
        }
        else {                          // if not a number char
            op1 = myStack.top();        //initialize the value to the op1 to the value of the top.
            myStack.pop();              // pops the top
            op2 = myStack.top();        //initialize the value to the op2 to the value of the new top.
            myStack.pop();               // pops the new top

            switch (equation[i])               //switch statement
            {
            case '+':                       // addition of op1 and op2  and push to the stack
                myStack.push(op1 + op2);
                break;
            case '-':
                myStack.push(op1 - op2);     // subtraction of op1 and op2 and push to the stack
                break;
            case '*':
                myStack.push(op1 * op2);    // multiplication of op1 and op2 and push to the stack
                break;
            case '/':
                if (op2 != 0)               // division of op1 and op2 and push to the stack
                    myStack.push(op1 / op2);
                else
                {
                    cout << " (Division by 0)";     // if op2 = 0, show msg and end
                    return 1;
                }
                break;
            default:                                // default case 
                cout << "try different equation";
                return 1;
            }
        }
    }
    cout << myStack.top(); // print the answer.

    return 0;

} //end main

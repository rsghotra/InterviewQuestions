#include<iostream>
#include<string>
#include<stack>

//BEDMAS
using namespace std;

bool isOperator(char ch) {
    if(ch == '(' || ch == ')' || ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-') {
        return true;
    }
    return false;
}

int OutStackPrecedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
            return 6; //look even
        case '(':
            return 7;
        case ')':
            return 0;
    }
    return -1;
}

int InStackPrecedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5; //look ODD for R-L OP
        case '(':
            return 0;
    }
    return -1;
}

void Infix_To_Postfix_Comp(char* exp) {
    string postfix{""};
    int i = 0;
    stack<char> stk;
    while(exp[i] != '\0') {
        if(!isOperator(exp[i])) {
            postfix.push_back(exp[i]);
            i++;
        }
        if(stk.empty() || OutStackPrecedence(exp[i]) > InStackPrecedence(stk.top())) {
            stk.push(exp[i]);
            i++;
        } else if(OutStackPrecedence(exp[i]) < InStackPrecedence(stk.top())) {
            postfix.push_back(stk.top());
            stk.pop();
            //not moving i
        } else {
            //this will only happen when you will see a closing bracket
            // corresponing opern brackets in the stack
            //we pop ( from stack and do nothing with it. Also increase i to next spot. Nothing will be done for ( bracket as well.
            stk.pop();
            i++;
        }
    }
    while(!stk.empty()) {
        postfix.push_back(stk.top());
        stk.pop();
    }
    cout << "Converted Postfix expression is: " << postfix << endl;
}

int main() {
    char expr[] = "(((a+b)*c)-d^e^f)";
    Infix_To_Postfix_Comp(expr);
    return 0;
}
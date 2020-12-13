#include<iostream>
#include<map>
#include<stack>
#include<string>
using namespace std;

/*
    - Infix to Postfix Basic with no associativity
        - Algo is very simple:
            - we do not act when we see operand
            - When we see operator:
                - If stack is empty - push it
                - Incoming opertor precedence is higher than top of stack - push on stack
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

int PrecedenceOf(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 0;
}

void Infix_To_Postfix_Basic(char* exp) {
    stack<char> stk;
    string postfix = "";
    int i = 0;

    while(exp[i] != '\0') {
        if(!isOperator(exp[i])) {
            postfix.push_back(exp[i]);
            i++;
        } else {
            if(stk.empty() || (PrecedenceOf(exp[i]) > PrecedenceOf(stk.top()))) {
                stk.push(exp[i]);
                i++;
            } else {
                postfix.push_back(stk.top());
                stk.pop();
            }
        }
    }
    while(!stk.empty()) {
        postfix.push_back(stk.top());
        stk.pop();
    }
    cout << "Postfix Expression: " << postfix << endl;
}

int main() {
    char exp_basic[] = "3*5+6/2-4";
    Infix_To_Postfix_Basic(exp_basic);
    return 0;
}
#include<iostream>
#include<stack>
using namespace std;

/*
    - POSTFIX EVALUATION - ONLY CASE WHERE WE PUSH OPERAND;
*/

bool isOperand(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') {
        return false;
    }
    return true;
}

void PostfixEvaluate(char* exp) {
    int i = 0;
    int x1; int x2; int res;
    stack<int> stk;
    //for loop can be used since we are incrementing in in every iteration
    for(i = 0; exp[i] != '\0'; i++) {
        if(isOperand(exp[i])) {
            //converting char to int
            stk.push(exp[i] - '0');
        } else {
            x2 = stk.top(); stk.pop();
            x1 = stk.top(); stk.pop();
            switch(exp[i]) {
                case '+':
                    res = x1 + x2;
                    break;
                case '*':
                    res = x1 * x2;
                    break;
                case '-':
                    res = x1 - x2;
                    break;
                case '/':
                    res = x1/x2;
                    break;
            }
            stk.push(res);
        }
    }
    cout << "Postfix evaluation:O(n): " << stk.top() << endl;
}


int main() {
    char postfix[]="42+351-*+";
    PostfixEvaluate(postfix);
    return 0;
}
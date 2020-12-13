#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

bool isBalanced(char* expr) {
    //create map
    map<char, char> mapping;
    mapping[')'] = '(';
    mapping['}'] = '{';
    mapping[']'] = '[';

    //create map iterator
    map<char, char>::iterator itr;

    stack<char> stk;

    for(int i = 0; expr[i] != '\0'; i++) {
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            stk.push(expr[i]);
        } else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if(stk.empty()) return false;
            char temp = stk.top();
            itr = mapping.find(expr[i]);
            if(temp == itr->second) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty() ? true : false;
}

int main() {
    char expr1[] = "{([a+b]*[c-d])/e}";
    cout << isBalanced(expr1) << endl;

    char expr2[] = "{([a+b]}*[c-d])/e}";
    cout << isBalanced(expr2) << endl;

    char expr3[] = "{([{a+b]*[c-d])/e}";
    cout << isBalanced(expr3) << endl;
    return 0;
}
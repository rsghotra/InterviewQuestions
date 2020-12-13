#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;

bool isBalanced(char* exp) {
    map<char, char> mappings;
    mappings[')'] = '(';
    mappings['}'] = '{';
    mappings[']'] = '[';
    stack<int> stk;
    map<char, char>::iterator itr;
    for(int i =0; exp[i] != '\0'; i++) {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stk.push(exp[i]);
        } else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if(stk.empty()) return true;
            char temp = stk.top();
            itr = mappings.find(exp[i]);
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
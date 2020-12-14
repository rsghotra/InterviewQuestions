#include<iostream>
#include<string>
using namespace std;

int Length(const string& str) {
    int i =0;
    for(i; str[i] != '\0'; i++) {}
    return i;
}

void ToggleCaser(string& str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        } else if(str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    string str1{"FaceBook Interview IS on jAN 7th 2020."};
    cout << "Length of " << Length(str1) << endl;
    ToggleCaser(str1);
    cout << str1 << endl;

}


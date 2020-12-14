#include<iostream>
using namespace std;

int main() {
    string str = "finding";

    int a;
    int H = 0;

    for(int i=0; i < str.length(); i++) {
        a = 1;
        a = a << str[i] - 97;

        //Masking is Asking
        if((a&H) > 0) {
            cout << "Duplicate Found: " << str[i] << endl;
        } else {
            //set the bit by performing a merge operation
            H = H | a;
        }
    }
    return 0;
}
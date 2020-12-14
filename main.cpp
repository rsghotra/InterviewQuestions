#include<iostream>
using namespace std;

//anagrams using Bitset
/*
    Algorithm:
        1. Traverse over str1 and perform merging on the Hash
        2. Traverse over second and perform masking to see if the bit was set
*/

void Anagrams_Bitset(string str1, string str2) {
    if(str1.length() != str2.length()) {
        cout << "Not Anagrams" << endl;
        return;
    }
    int H = 0;
    int a;
    for(int i=0; i < str1.length(); i++) {
        a = 1;
        a = a << str1[i] - 97;
        H = H | a;
    }

    for(int j = 0; j < str2.length(); j++) {
        a = 1;
        a = a << str2[j] - 97;

        if((H&a) == 0) {
            cout << "Not Anagrams" << endl;
            return;
        }
    }
    cout << "Anagrams" << endl;
}

int main() {
    //assumimg no duplicacates
    string str1 = "medicab";
    string str2 = "decimal";
    Anagrams_Bitset(str1, str2);
}
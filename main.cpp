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

void CountVowelsAndConsonants(string& str1) {
    int vowels=0;
    int consonants=0;
    for(int i=0; i < str1.length(); i++) {
        if(str1[i] == 'A' || str1[i] == 'a' || str1[i] == 'E' || str1[i] == 'e' || str1[i] == 'I' ||
            str1[i] == 'i' || str1[i] == 'O' || str1[i] == 'o' || str1[i] == 'U' || str1[i] == 'u') {
                vowels++;
        } else consonants++;
    }
    cout << "Number of Vowels: " << vowels << endl;
    cout << "Number of Consonants: " << consonants << endl;
}

void WordCalculator(string& str) {
    //no of words = space + 1; Space's ASCII code = 13
    int space=0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ' ' && str[i-1] != ' ') {
            space++;
        }
    }
    cout << "Number of words are: " << space+1 << endl;
}

void Swap(char& x, char& y) {
    
}

void Reverse(string& str) {
    int i =0;
    int j = str.length() - 1;
    for(i, j; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;;
    }
    cout << "String after Reversing: " << str << endl;
}

int main() {
    string str1{"FaceBook Interview IS on jAN 7th 2020."};
    cout << "Length of " << Length(str1) << endl;
    ToggleCaser(str1);
    cout << str1 << endl;
    CountVowelsAndConsonants(str1);
    WordCalculator(str1);
    Reverse(str1);
    Reverse(str1);
    return 0;
}


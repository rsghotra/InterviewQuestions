#include<iostream>
#include<string>
#include<cctype>
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

void isPalindrome(string& str) {
    int i = 0;
    int j = str.length()-1;

    for(i,j; i < j; i++, j--) {
        if(tolower(str[i]) != tolower(str[j])) {
            cout << "Not Palindrome" << endl;
            return;
        }
    }
    cout << "Palindrome" << endl;
}

void Reverse(string str) {
    int i =0;
    int j = str.length() - 1;
    for(i, j; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;;
    }
    cout << "String after Reversing: " << str << endl;
}

void Compareor(string& str1, string& str2) {
    int i = 0; 
    int j = 0;
    for(i,j; i < str1.length() && j < str2.length(); i++, j++) {
        if(str1[i] != str2[i]) {
            break;
        }
    }
    if(str1[i] == '\0' && str2[j] == '\0') {
        cout << "Same Strings" << endl;
    }
    else if(str1[i] < str2[j]) {
        cout << "Second string is larger than first string" << endl;
    } else if(str1[i] > str2[j]) {
        cout << "First string is larger than the second string" << endl;
    }
}

/*
    - Both strings must be of same length
    - Both string must consists of same letters
    - Iterative Solution Presented Here - Do not expect duplicated in the string
    - Hash Table Solutions Can Work on strings containing duplicates
*/

void AreAnagrams_Bitset(string& str1, string& str2) {

}

void AreAnagrams_Hash(string& str1, string& str2) {
    if(str1.length() != str2.length()) {
        cout << "Strings are not Anagrams" << endl;
        return;
    }
    int Hash[27]{0}; //initialized with zero
    //traverse over str1
    for(int i=0; str1[i] != '\0'; i++) {
        Hash[str1[i] - 97]++;
    }
    for(int j=0; str2[j] != '\0'; j++) {
        Hash[str2[j] - 97]--;
        if(Hash[str2[j] - 97] < 0) {
            cout << "Strings are not Anagrams." << endl;
            return;
        }
    }
    cout << "Strings are Anagrams." << endl;
}

void Duplicates_Hash(string& str) {
    int Hash[27]{0};

    for(int i=0; i < str.length(); i++) {
        Hash[str[i] - 97]++;
    }
    for(int i = 1; i < 27; i++) {
        if(Hash[i] > 1) {
            cout << char(i+97) << " is repeating " << Hash[i] << " times." << endl;
        }
    }
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
    string str2 = "Ranveer";
    isPalindrome(str2);
    Compareor(str1, str2);
    string str3 = "delcimal";
    string str4 = "medicall";
    AreAnagrams_Hash(str3, str4);
    string str5 = "ranveer";
    Duplicates_Hash(str5);
    return 0;
}


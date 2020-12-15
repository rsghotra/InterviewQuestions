#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

//https://www.geeksforgeeks.org/find-possible-words-phone-digits/ 

/*
    1. Map the number with its string of probable alphabets i.e. 2 with "abc", 3 with "def"
    2. Create a recursive function which takes the following parameters:
        a. output string
        b. input number array
        c. current index
    3. Extract the string from the map
    4. Run a loop to traverse the string from start to end
    5. For every index again call the recursive function woth the output string concatenated with the ith character of the string
*/

// string getString(int key) {
//     map<int, string> mappings;
//     mappings[0] = "";
//     mappings[1] = "";
//     mappings[2] = "abc";
//     mappings[3] = "def";
//     mappings[4] = "ghi";
//     mappings[5] = "jkl";
//     mappings[6] = "mno";
//     mappings[7] = "pqrs";
//     mappings[8] = "tuv";
//     mappings[9] = "wxyz";

//     return mappings[key];
// }

// void GenerateWords(vector<int> number, string output) {
//     static int numberIndex = 0;
//     int i;
//     if(numberIndex == number.size() - 1) {
//         cout << output << endl;
//         return;
//     }

//     //try all three possible characters for the current digit in number[] and recur the remaining digit
//     for(i = 0; i < getString(number[numberIndex]).length(); i++) {
//         output[numberIndex] = getString(number[numberIndex])[i];
//         numberIndex++;
//         GenerateWords(number, output);
//         if(number[numberIndex] == 0 || number[numberIndex] == 1) {
//             return;
//         }
//     }

// }

// void PrintWords(vector<int> number) {
//     string output = "";
//     GenerateWords(number, output);
// }


// int main() {
//     vector<int> number{7,7,8,9,7,7,3,8};
//     PrintWords(number);
//     return 0;
// }

const char hashTable[10][5]
    = { "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz" };
 
// A recursive function to print all possible words that can
// be obtained by input number[] of size n.  The output
// words are one by one stored in output[]
void printWordsUtil(int number[], int curr_digit,
                    char output[], int n)
{
    // Base case, if current output word is prepared
    int i;
    if (curr_digit == n) {
        printf("%s ", output);
        return;
    }
 
    // Try all 3 possible characters for current digir in
    // number[] and recur for remaining digits
    for (i = 0; i < strlen(hashTable[number[curr_digit]]);
         i++) {
        output[curr_digit]
            = hashTable[number[curr_digit]][i];
        printWordsUtil(number, curr_digit + 1, output, n);
        if (number[curr_digit] == 0
            || number[curr_digit] == 1)
            return;
    }
}
 
// A wrapper over printWordsUtil().  It creates an output
// array and calls printWordsUtil()
void printWords(int number[], int n)
{
    char* res = new char[n+1];
    res[n] = '\0';
    printWordsUtil(number, 0, res, n);
}
 
// Driver program
int main(void)
{
    int number[] = { 2, 3, 4 };
    int n = sizeof(number) / sizeof(number[0]);
    printWords(number, n);
    return 0;
}
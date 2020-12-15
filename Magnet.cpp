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


 //Design a set of class definitions (interfaces, api) for wrapping access to a file system.
 
//  class File: public Folder {
//     public:
//         File();
//         File(string path);
//         File CreateFile(string path);
//         File OpenFile();
//         bool CloseFile();
//         bool Exists();
//         string GetName();
//         void Rename(string path);
//         bool SetData(string data);
//         iostream& operator<<(File& file, T data);
// };

// class Folder {
//     private:
//         string Name;
//         Time dateOfCreation;
//         File files[];
//         File file;
//     public:
//         Folder(){}
//         Folder CreateDirectory(string path)
//         Folder Open(string path)
//         bool Close()
//         Files[] getFiles();
//         Folder[] getSubs();
//         Time getCreationTime()
//         bool Exists()
//         Folder GetParent()
//         Folder Move(string destination)
// };
 
 
//  class FileData:  {
//      private:
//      public:
//          virtual void setData(File file, T data) = 0;
//          virtual void modifyData(File file, T data) = 0;
//          virtual T convert(File file, T1 data, T2 data)=0;
// };

// Write a function that takes in a root and a file name, and returns the count of the files with that name. 

// "c:\test" <- Input 1
// "test.txt" <- Input 2
// "c:\test\inner\test.txt" <- Possible folder structure

int CountSameNames(Folder folder, string name) {
    int count = 0;
    File files[] = folder.getFiles();
    for(int i = 0; i < files.length(); i++) {
        if(files[i].getName() == name) {
            count++;
    }
    name = "test.txt"
    folder == "c:\test"
    Folder folders[] = folder.getFolders();
    for(int i = 0; i < folders.length(); i++) {
        File files[] = folders[i].getFiles();
        for(int j = 0; j < files.length(); j++) {
            if(files[i].GetName() == name) {
                count++;
             }
        }
    }
    return count;
}

         
int main()
{
   string myFileData = "Hello, world";
   string path = "C:\test\test.txt";  
   
   File file = new File();
   file.CreateFile(path);
   file.OpenFile();
   file << myFileData << endl;
   try {
    file.CloseFile();
   } catch(exeception& ex) {
       cout << ex.what() << endl;
   }
   
}
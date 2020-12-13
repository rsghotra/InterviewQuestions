#include<iostream>
#include<iostream>
using namespace std;

/*
    1. Declaring a 2D array in Stack
    2. Declare a 2D array partial in Heap and Partial in stack
    3. Declare a 2D array fully in Heap
*/

int main() {
    cout << "2D array in stack" << endl;
    int A[3][4] = {{1,2,3,4}, {5,6,7,8}, {9, 10, 11, 12}};

    for(int i=0; i < 3; i++) {
        for(int j=0; j < 4; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Partial in Stack and Partial in Heap" << endl;
    int* Array[3];
    Array[0]=new int[4]();
    Array[1]=new int[4]();
    Array[2]=new int[4]();
    Array[3]=new int[4]();

    for(int i=0; i < 3; i++) {
        for(int j=0; j < 4; j++) {
            cout << Array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Fully in Heap - Remember heap memory - C++ does initialize" << endl;
    int** dPtr;
    dPtr = new int*[3];
    dPtr[0] = new int[4]();
    dPtr[1] = new int[4]();
    dPtr[2] = new int[4]();
    dPtr[3] = new int[4]();

    for(int i=0;i<3;i++) {
        for(int j=0;j<4;j++) {
            std::cout << dPtr[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

}
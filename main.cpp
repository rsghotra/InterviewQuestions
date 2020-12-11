#include<iostream>
#include<vector>
using namespace std;

/*
    Find Missing Element(s):
        a. Multiple Missing Element:
            1. Sorted Array - Sophisticated Counter Manipulation
            2. Unsorted Array - Hash Table
*/
bool isSorted(const vector<int>& vect) {
    bool status = false;
    for(int i = 0; i < vect.size() - 1; i++) {
        if(vect.at(i) > vect.at(i+1)) {
            return status;
        }
    }
    status = true;
    return status;
}

void FindMultipleMissingElems_SORTED(const vector<int>& vect) {

    //i will need three thigs. l, h, n
    int low = vect[0];
    int high = vect[vect.size() - 1 ];
    int index = 0;
    int diff = low - index;

    cout << "Missing elements in a sorted array: " << endl;
    for(int i=0; i < vect.size(); i++) {
        int indexDifference = vect.at(i) - i;
        if(indexDifference != diff) {
            while(diff < indexDifference) {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
    cout << endl;

}

int Max(const vector<int>& vect1) {
    int max = INT_MIN;
    for(int i = 0; i < vect1.size(); i++) {
        if(vect1.at(i) > max)  max = vect1.at(i);
    }
    return max;
}

int Min(const vector<int>& vect1) {
    int min = INT_MAX;
    for(int i = 0; i < vect1.size(); i++) {
        if(vect1.at(i) < min)  min = vect1.at(i);
    }
    return min;
}

void FindMultipleMissingElems_UNSORTED(const vector<int>& vect) {
    int low = Min(vect);
    int high = Max(vect);

    int* H = new int[high+1]();

    for(int i = 0; i < vect.size(); i++) {
        H[vect.at(i)]++;
    }
    cout << "Multiple missing elements from UNSORTED: ";
    for(int j = low; j <= high; j++) {
        if(H[j] == 0) {
            cout << j << " ";
        }
    }
    cout << endl;

}

void FindMultipleMissingElem(const vector<int>& vect) {
    if(isSorted(vect)) FindMultipleMissingElems_SORTED(vect);
    else FindMultipleMissingElems_UNSORTED(vect);
}


int main() {
    vector<int> vect1{1,4,6,8,10,12,14};
    FindMultipleMissingElems_SORTED(vect1);
    vector<int> vect2{3,7,4,9,12,6,1,11,2,10};
    FindMultipleMissingElems_UNSORTED(vect2);
}
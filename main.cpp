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


void FindMultipleMissingElems_SORTED(const vector<int> vect) {
    if(isSorted(vect)) {
        int index = 0;
        int diff = vect[0] - index;
        cout << "Multiple Missing Elements in a Sorted List: " << endl;
        for(int i = 0; i < vect.size(); i++) {
            //diff is found by reading index number and element present at the index
            int travelDiff = vect.at(i) - i;
            if(travelDiff != diff) {
                //missing elements found
                //need to bring diff to travel diff in order to travel further
                while(diff < travelDiff) {
                    //diff + i will give the first number what it should have been there
                    cout << diff + i << " ";
                    diff++;
                }
            }
        }
        cout << endl;
    }
}

void FindMultipleMissingElems_UNSORTED(const vector<int> vect) {
    //vector must be unsorted for this algorithm
    //max - min & Hash Table will be used
    if(!isSorted(vect)) {
        cout << "Finding Multiple Missing elements in an Unsorted Array: " << endl;
        int max = Max(vect);
        int min = Min(vect);
        //HASH size must be max+1 as we will not use index 1
        int* H = new int[max+1]();

        for(int i = 0; i < vect.size(); i++) {
            H[vect.at(i)]++;
        }

        for(int j = min; j <= max; j++) {
            if(H[j] == 0) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

void FindMultipleMissingElem(const vector<int>& vect) {
    if(isSorted(vect)) FindMultipleMissingElems_SORTED(vect);
    else FindMultipleMissingElems_UNSORTED(vect);
}


int main() {
    vector<int> vect1{1,4,6,8,10,12,14,18};
    FindMultipleMissingElems_SORTED(vect1);
    vector<int> vect2{3,7,4,9,12,6,1, 11, 2, 10, 14};
    FindMultipleMissingElems_UNSORTED(vect2);
}
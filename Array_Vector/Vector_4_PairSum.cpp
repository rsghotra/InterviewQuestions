#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    Find Pair Sum - Sorted(Single and Multiple)
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

void FindPairSumK_SORTED(const vector<int> vect, int k) {
    //because the list is sorted - hence very less efforts need to be made
    int i = 0;
    int j = vect.size() - 1;
    cout << "Finding pair sum in a sorted Vector." << endl;
    while( i < j) {
        if((vect[i] + vect[j]) == k) {
            cout << vect.at(i) << " + " << vect.at(j) << " = " << k << endl;
            i++;
            j--;
        } else if((vect[i] + vect[j]) < k) {
            //means to increase i. Not J
            i++;
        } else {
            j--;
        }
    }
}

void FindPairSumK_UNSORTED(const vector<int> vect, int k) {
    int min = Min(vect);
    int max = Max(vect);
    if(k > max) {
        return; //unless array contains negative values
    }
    cout << "Finding pair sum in a UNSORTED Vector." << endl;
    int* H = new int[max+1]();
    //kya hi diya hai - filling and using hash together! - This happen when both setup and answer is co-rrelated to original array.
    for(int i = 0; i < vect.size(); i++) {
        if(k - vect.at(i) >= 0) {
            if(H[k - vect.at(i)] != 0) {
                cout << vect.at(i) << " + " << k-vect.at(i) << " = " << k << endl;
            }
            H[vect.at(i)]++;
        }
    }
}

int main() {
    vector<int> vect1{1,3,4,5,6,8,9,10,12,14};
    FindPairSumK_SORTED(vect1, 9);
    vector<int> vect2{6,3,8,10,16,7,5,2,9,14};
    FindPairSumK_UNSORTED(vect2, 10);
    return 0;
}
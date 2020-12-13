#include<iostream>
#include<vector>
using namespace std;

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


void FindDuplicates_Sorted(const vector<int>& vect) {
    int lastDuplicate = 0;
    cout << "Duplicates in sorted list: " << endl;
    for(int i = 0; i < vect.size() - 1; i++) {
        if(vect.at(i) == vect.at(i+1) && lastDuplicate != vect.at(i)) {
            lastDuplicate = vect.at(i);
            cout << lastDuplicate << " ";
        }
    }
    cout << endl;
}

void FindAndCountDuplicates_Sorted(const vector<int>& vect) {
    int i, j;
    cout << "Finding and Counting Duplicates in a Sorted List." << endl;
    for(i=0; i < vect.size()-1; i++) {
        if(vect.at(i) == vect.at(i+1)) {
            j = i + 1;
            while(vect.at(j) == vect.at(i)) {
                j++;
            }
            cout << vect.at(i) << " is repeating " << j - i << " times." << endl;
            i = j-1;
        }
    }
}

void FindAndCountDuplicates_UnSorted(const vector<int>& vect) {
    int max = Max(vect);
    int min = Min(vect);
    cout << "Finding and Counting Duplicates in an UnSorted List." << endl;
    int* H = new int[max+1]();
    for(int i = 0; i < vect.size(); i++) {
        H[vect.at(i)]++;
    }
    for(int j = min; j <= max; j++) {
        if(H[j] > 1) {
            cout << j << " is repeating " << H[j] << " times." << endl;
        }
    }
}

int main() {
    vector<int> vect{3,6,8,8,10,12,15,15,15,20};
    FindDuplicates_Sorted(vect);
    FindAndCountDuplicates_Sorted(vect);
    vector<int> vect2{8,3,6,4,6,5,6,8,2,7};
    FindAndCountDuplicates_UnSorted(vect2);
    return 0;
}

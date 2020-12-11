#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    Find Pair Sum - Sorted(Single and Multiple)
*/

void FindPairSumK_SORTED(const vector<int> vect, int k) {
    //because the list is sorted - hence very less efforts need to be made
    int i = 0;
    int j = vect.size() - 1;
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

int main() {
    vector<int> vect{1,3,4,5,6,8,9,10,12,14};
    FindPairSumK_SORTED(vect, 9);
    return 0;
}
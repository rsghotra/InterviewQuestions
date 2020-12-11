#include<iostream>
#include<vector>
using namespace std;


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

vector<int> MergeSorted(const vector<int> vect1, const vector<int> vect2) {
    vector<int> vect3;
    if(vect1.empty() && vect2.empty()) return vect3;
    if(vect1.empty() && !vect2.empty()) return vect2;
    if(!vect1.empty() && vect2.empty()) return vect1;

    int i = 0, j = 0;
    while(i < vect1.size() && j < vect2.size()) {
        if(vect1.at(i) <= vect2.at(j)) {
            vect3.push_back(vect1.at(i));
            i++;
        } else {
            vect3.push_back(vect2.at(j));
            j++;
        }
    }
    while(i < vect1.size()) {
        vect3.push_back(vect1.at(i));
        i++;
    }
    while(j < vect2.size()) {
        vect3.push_back(vect2.at(j));
        j++;
    }
    return vect3;
}

void Display(vector<int> vect) {
    for( const int& ele: vect) {
        cout << ele << " ";
    }
    cout << endl;
}

void Separator(vector<int>& vect) {
    int i = 0;
    int j = vect.size() - 1;

    while( i < j ) {
        while(vect.at(i) < 0) {
            i++;
        }
        while(vect.at(j) >= 0) {
            j--;
        }
        //again checking because if in perfect array. Both will just increase and becomes i > j but the check will happen in next iteration
        if(i < j) {
            std::swap(vect.at(i), vect.at(j));
        }
    }
}

void Insert(vector<int>& vect, int data) {
    int i = vect.size() - 1;
    vect.push_back(0);
    while(vect.at(i) >= data) {
        vect.at(i) = vect.at(i-1);
        i--;
    }
    vect[i+1] = data;
}


int main() {
    vector<int> vect1{1,4,6,8,10,12,14};
    vector<int> vect2{1,3,5,7,9,11,13,15};
    
    isSorted(vect1) ? cout << "Vector is sorted" << endl : cout << "Vector is not sorted" << endl;
    vector<int> vect3 = MergeSorted(vect1, vect2);
    Display(vect3);

    cout << "Inserting in a sorted array: " << endl;
    Insert(vect3, 2);
    Display(vect3);

    vector<int> vect4{-6,3,-8,10,5,-7,-9,12,-4, 2};
    Display(vect4);
    cout << "Separating +ve and -ve numbers" << endl;
    Separator(vect4);
    Display(vect4);



    return 0;
}


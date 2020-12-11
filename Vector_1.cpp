#include<iostream>
#include<vector>
#include<algorithm>
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


vector<int> Union_UnSorted(const vector<int>& vect1, const vector<int>& vect2) {
    // O(m + m*n) = O(n2)
    vector<int> output;
    int i = 0;
    //copy first set - O(m)
    while(i < vect1.size())
    {
        output.push_back(vect1.at(i));
        i++;
    }

    for(int j = 0; j < vect2.size(); j++) {
        bool found = false;
        for(int k = 0; k < vect1.size(); k++) {
            if(vect1.at(k) == vect2.at(j)) {
                found = true;
            }
        }
        if(!found) {
            output.push_back(vect2.at(j));
        }
    }
    return output;
}

vector<int> Union(const vector<int>& set1, const vector<int>& set2) {
    //O(m+n) => O(n)
    //it will be like merting two sorted vector
    vector<int> output;
    if(isSorted(set1) && isSorted(set2)) {
        int i = 0;
        int j = 0;
        while(i < set1.size() && set2.size()) {
            if(set1.at(i) < set2.at(j)) {
                output.push_back(set1.at(i));
                i++;
            } else if(set1.at(i) > set2.at(j)) {
                output.push_back(set2.at(j));
                j++;
            } else {
                output.push_back(set1.at(i));
                i++;
                j++;
            }
        }
    }
    return output;
}

vector<int> Intersection(const vector<int>& vectX, const vector<int>& vectY) {
    vector<int> output;
    if(isSorted(vectX) && isSorted(vectY)) {
        int i = 0;
        int j = 0;
        while(i < vectX.size() && j < vectY.size()) {
            if(vectX.at(i) < vectY.at(j)) {
                i++;
                j++;
            } else if(vectX.at(i) > vectY.at(j)) {
                i++;
                j++;
            } else {
                output.push_back(vectX.at(i));
                i++;
                j++;
            }
        }
    }
    return output;
}

vector<int> Difference(const vector<int>& vect1, const vector<int>& vect2) {
    vector<int> output;
    if(isSorted(vect1) && isSorted(vect2)) {
        int i = 0;
        int j = 0;
        while(i < vect1.size() && j < vect2.size()) {
            if(vect1.at(i) < vect2.at(j)) {
                output.push_back(vect1.at(i));
                i++;
            } else if(vect1.at(i) > vect2.at(j)) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        //As it is A - B. We only need to copy left over element of A
        while(i < vect1.size()) {
            output.push_back(vect1.at(i));
            i++;
        }
    }
    return output;
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
    cout << "Separating +ve and -ve numbers: ";
    Separator(vect4);
    Display(vect4);

    cout << "Set Operations Union, Find, Intersection, Difference: " << endl;
    vector<int> set1{3,5,10,4,6,11};
    vector<int> set2{12,4,7,2,5};

    vector<int> set3 = Union_UnSorted(set1, set2);
    cout << "Displaying Union of two Unsorted Sets: " << endl;
    cout << "Set1: ";
    Display(set1);
    cout << "Set2: ";
    Display(set2);
    cout << "Union-Unsorted Set: " << endl;
    Display(set3);

    cout << "==>UNION of TWO SORTED SETS: " << endl;
    std::sort(set1.begin(), set1.end());
    std::sort(set2.begin(), set2.end());
    cout << "Displaying Union of two SORTED Sets(O(N)): " << endl;
    cout << "Set1: ";
    Display(set1);
    cout << "Set2: ";
    Display(set2);
    set3 = Union(set1, set2);
    cout << "Union-Sorted Sets: " << endl;
    Display(set3);
    cout << "Intersection-Sorted Sets: " << endl;
    set3 = Intersection(set1, set2);
    Display(set3);

    cout << "Difference-Sorted Sets: " << endl;
    set3 = Difference(set1, set2);
    Display(set3);
    return 0;
}


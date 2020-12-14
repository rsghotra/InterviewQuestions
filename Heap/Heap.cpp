#include<iostream>
#include<vector>
using namespace std;

void Swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void Heapify(vector<int>& vect) {
    int i = vect.size() - 1;
    int j;

    while(i >= 1) {
        j = 2*i;
        if(j+1 < vect.size()) {
            //finalise children
            if(vect.at(j+1) > vect.at(j)) {
                j = j+1;
            }
            if(vect.at(j) > vect.at(i)) {
                Swap(vect.at(i), vect.at(j));
            }
        } else if(j < vect.size()) {
            if(vect.at(j) > vect.at(i)) {
                Swap(vect.at(i), vect.at(j));
            }
        }
        i--;
    }
}

void Delete(vector<int>& Heap, int lastEleIndex) {
    int val = Heap.at(1);
    Heap.at(1) = Heap.at(lastEleIndex);
    int i = 1;
    int j = 2*i;

    //because last element is deleted and not part of the heap.
    while(j < lastEleIndex) {
        if(Heap.at(j+1) > Heap.at(j)) {
            j++;
        }
        if(Heap.at(j) > Heap.at(i)) {
            Swap(Heap.at(i), Heap.at(j));
            i = j;
            j = 2*i;
        } else {
            //node is at right place
            break;
        }
    }
    Heap.at(lastEleIndex) = val;
}

void Insert(vector<int> Heap, int n) {
    int x = Heap[n]; //value to be inserted in heap and adjusted
    int i = n;
    while(i > 1 && x > Heap.at(i/2)) {
        Heap.at(i) = Heap.at(i/2);
        i = i/2;
    }
    Heap.at(i) = x;
}

void Display(const vector<int>& vect) {
    cout << "Heap: ";
    for(int i =1; i < vect.size(); i++) {
        cout << vect.at(i) << " ";
    }
    cout << endl;
}

void HeapSort(vector<int>& Heap) {
    for(int i = Heap.size()-1; i >= 1; i--) {
        Delete(Heap, i);
    }
}

int main() {
    vector<int> vect{0,5,10,30,20,35,40,15,41,77};
    Heapify(vect);
    Display(vect);
    HeapSort(vect);
    Display(vect);
}
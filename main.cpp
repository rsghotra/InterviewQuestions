#include<iostream>
#include<stdexcept>
#include<exception>
#include<random>
#include<ctime>
using namespace std;

class Array {
    private:
        int length;
        int size;
        int* A;
    public:
        Array() {
            this->length = 0;
            this->size = 0;
            A = new int[this->size];
        }
        Array(int size) {
            this->length = 0;
            this->size = size;
            this->A = new int[this->size];
        }
        ~Array() {
            delete [] A;
            A = 0;
        }
        void Display() const;
        void Insert(const int&, const int&);
        void Append(const int&);
        int  Delete(const int&);
};

void Array::Display() const {
    if(this->length == 0) return;
    for(int i{0}; i < this->length ; i++) {
        cout << this->A[i] << " ";
        if(i%5 == 0) cout << endl;
    }
    cout << endl;
}

void Array::Insert(const int& index, const int& data) {
    //we will check if index supplied is valid
    if( index < 0 ) {
        throw invalid_argument("Index can not be negative");
    }
    if( index > this->size - 1) {
        throw out_of_range("Index is greater than the size of the array.");
    }
    if(this->length == this->size) {
        throw std::exception{};
    }

    for(int i{this->length - 1}; i >= index; i--) {
        this->A[i+1] = this->A[i];
    }
    this->A[index] = data;
    this->length++;
}

void Array::Append(const int& val) {
    if(this->length == this->size) {
        throw out_of_range("Array is full");
    }
    this->A[length] = val;
    this->length++;
}

int Array::Delete(const int& index) {
    if(index < 0 || this->length == 0 || this->size == 0) {
        throw invalid_argument("Index supplied in out of range.");
    }
    int val = this->A[index];
    for(int i{index}; i+1 <= (this->length - 1); i++) {
        this->A[index] = this->A[index+1];
    }
    this->length--;
    return val;
}

int main() {

    default_random_engine engine{static_cast<unsigned int>(time(0))};
    uniform_int_distribution<unsigned int> randomInt{1, 100};

    Array arr(200);

    for(size_t i{0}; i < 100; ++i) {
        arr.Insert(i, randomInt(engine));
    }
    arr.Insert(100, 101);
    arr.Display();

    for(int i{0}; i < 101; i++) {
        cout << "Deleted: " << arr.Delete(i) << " ";
        if(i%5 == 0) cout << endl;
    }
    cout << endl;
    arr.Append(1);
    arr.Display();
    return 0;
}
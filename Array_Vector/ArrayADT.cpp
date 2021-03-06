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
        int  Get(const int&) const;
        void Set(const int&, const int&) const;
        int  Search(const int&) const;
        int  Search_TRANSPOSE(const int& val);
        int  Search_MOVE_HEAD(const int& val);
        void Swap(int& x, int& y);
        void MinMax() const;
        void Reverse();
        void LeftShift();
        void LeftRotate();
        void RightShift();
        void RightRotate();
        double Avg() const;
};

double Array::Avg() const {
    double avg;
    double sum;
    for(int i = 0; i < this->length; i++) {
        sum += this->A[i];
    }
    return sum/this->length;
}

int Array::Search(const int& val) const {
    if(this->length == 0) return -1;
    for(int i{0}; i < this->length; i++) {
        if(this->A[i] == val) {
            return i;
        }
    }
    return -1;
}

void Array::Swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int Array::Search_TRANSPOSE(const int& val) {
    if(this->length == 0) return -1;
    for(int i{0}; i < this->length; i++) {
        if(this->A[i] == val) {
            if(i != 0) {
                this->Swap(this->A[i], this->A[i-1]);
            }
            return i;
        }
    }
    return -1;
}

int Array::Search_MOVE_HEAD(const int& val) {
    if(this->length == 0) return -1;
    for(int i{0}; i < this->length; i++) {
        if(this->A[i] == val) {
            if(i!=0) {
                this->Swap(this->A[0], this->A[i]);
            }
            return i;
        }
    }
    return -1;
}

int Array::Get(const int& index) const{
    if(index < 0 || index > this->length) {
        throw invalid_argument("Invalid index.");
    }
    return this->A[index];
}

void Array::Set(const int& index, const int& data) const{
    if(index < 0 || index > this->length - 1) {
        throw out_of_range("Out of bound index is given.");
    }
    this->A[index] = data;
}

void Array::Display() const {
    if(this->length == 0) return;
    for(int i{0}; i < this->length ; i++) {
        cout << this->A[i] << " ";
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

void Array::MinMax() const {
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0; i < this->length; i++) {
        if(this->A[i] < min) {
            min = this->A[i];
        } else if(this->A[i] > max) {
            max = this->A[i];
        }
    }
    cout << "Max Element in the array: " << min << endl;
    cout << "Min Element in the array: " << max << endl;
}

void Array::Reverse() {
    for(int i = 0, j = this->length-1; i < j; i++, j--) {
        this->Swap(this->A[i], this->A[j]);
    }
}

//KEY FOR ROTATION AND SHIFTING IS BOUND CHECK WILL HAPPEN ON (i+1) or (i-1)
void Array::LeftShift() {
    int i;
    for(i = 0; i+1 < this->length; i++) {
        //backward copy
        this->A[i] = this->A[i+1];
    }
    this->A[i] = 0;
}

void Array::LeftRotate() {
    int i = 0;
    int val = this->A[i];
    for(i; i+1 < this->length; i++) {
        this->A[i] = this->A[i+1];
    }
    this->A[i] = val;
}

void Array::RightShift() {
    int i;
    for(i = this->length-1; i-1 >=0; i--) {
        this->A[i] = this->A[i-1];
    }
    this->A[i] = 0;
}

void Array::RightRotate() {
    int i;
    int val = this->A[this->length-1];
    for(i = this->length-1; i-1 >= 0; i--) {
        this->A[i] = this->A[i-1];
    }
    this->A[i] = val;
}

int main() {

    default_random_engine engine{static_cast<unsigned int>(time(0))};
    uniform_int_distribution<unsigned int> randomInt{1, 100};

    Array arr(20);

    for(size_t i{0}; i < 10; ++i) {
        arr.Insert(i, randomInt(engine));
    }
    arr.Insert(3, 101);
    arr.Display();

    // for(int i{0}; i < 10; i++) {
    //     cout << "Deleted: " << arr.Delete(i) << " ";
    //     if(i%5 == 0) cout << endl;
    // }
    // cout << endl;
   
    arr.Display();
    cout << "Setting: -99 at index 0" << endl;
    arr.Set(0, -99);
    cout << "Getting: " << arr.Get(0) << endl;

    for(int i{0}; i < 10; i++) {
        int val = randomInt(engine);
        cout << "Searching(Transpose)for " <<  val << " and found at " << arr.Search_TRANSPOSE(val)<< endl;
        arr.Display();
        cout << "Searching for(Move Head) " <<  val << " and found at " << arr.Search_MOVE_HEAD(val)<< endl;
        arr.Display();
    }

    arr.MinMax();
    arr.Reverse();
    arr.Display();

    cout << "Rotation of Arrays: " << endl;
    arr.LeftShift();
    cout << "Left Shifted: ";
    arr.Display();
    arr.LeftRotate();
    cout << "Left Rotate: ";
    arr.Display();
    arr.RightShift();
    cout << "Right Shifted: ";
    arr.Display();
    
    arr.RightRotate();
    cout << "Right Rotate: ";
    arr.Display();
    
    cout << "Displaying Average of Array: " << endl;
    cout << arr.Avg();

    return 0;
}
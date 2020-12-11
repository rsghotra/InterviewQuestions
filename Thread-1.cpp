#include<iostream>
#include<thread>
using namespace std;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findOddSum(ull start, ull end) {
    for(ull i = start; i <= end; i++) {
        if(i%2 != 0) {
            oddSum += i;
        }
    }
}

void findEvenSum(ull start, ull end) {
    for(ull i = start; i <= end; i++) {
        if(i%2 == 0) {
            evenSum += i;
        }
    }
}


int main() {
    ull start = 0;
    ull end = 190000000;
    std::thread t1(findEvenSum, start, end);
    std::thread t2(findOddSum, start, end);

    t1.join();
    t2.join();
    cout << "Even Sum: " << evenSum << endl;
    cout << "Odd Sum: " << oddSum << endl;
    return 0;
}

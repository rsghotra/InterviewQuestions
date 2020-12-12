#include<iostream>
using namespace std;


int F[100];
int Fact[20];

int Sum(int n) {
    if(n == 1) {
        return 1;
    }
    return n + Sum(n-1);
}


int fact(int n) {
    if(n == 0) return 1;
    else return n*fact(n-1);
}

int fib(int n) {
    if(n <= 1) {
        F[n] = n;
        return F[n];
    } else {
        if(F[n-2] == -1) {
            F[n-2] = fib(n-2);
        }
        if(F[n-1] == -1) {
            F[n-1] = fib(n-1);
        }
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
}

int Combination(int n, int r) {
    if( n == r || r == 0) {
        return 1;
    } else {
        return Combination(n-1, r-1) + Combination(n-1, r);
    }
}

int Power(int m, int n) {
    if( n == 0) {
        return 1;
    } 
    if(n%2 == 0) {
        return Power(m * m, n/2);
    } else {
        return m * Power(m * m, (n-1)/2);
    }
}

int main() {
    int n;
    cout << "Enter fib(n): ";
    cin >> n;
    
    for(int i = 0; i < 100; i++) {
        F[i] = -1;
    }
    for(int i = 0; i < 50; i++) {
        Fact[i] = -1;
    }
    cout << fib(n) << endl;

    cout << "Enter number to find fact(n): ";
    cin >> n;
    cout << fact(n) << endl;

    int r;
    cout << "Enter n and r for Combination(n, r): ";
    cin >> n >> r;
    cout << Combination(n, r) << endl;

    int m, k;
    cout << "Enter m and n for power(m, n): ";
    cin >> m >> k;
    cout << Power(m, k) << endl;

    cout << "Enter n for Sum(n): ";
    cin >> n;
    cout << Sum(n) << endl;
    return 0; 
}
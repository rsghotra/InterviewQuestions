#include<vector>
#include<iostream>
#include<string>
#include<limits>
using namespace std;

int Solve(vector<int> &A, int B) {
    if(B > A.size()) return 0;
    
    vector<int> LeftSum;
    vector<int> RightSum;
    
    int sum = 0;
    
    for(int i = 0; i < B; i++) {
        sum += A.at(i);
        LeftSum.push_back(sum);
    }
    
    sum = 0;
    
    for(int j = A.size() - B; j < A.size(); j++) {
        sum+= A.at(j);
        RightSum.push_back(sum);
    }
    
    int m = 0;
    
    for(int i = 0; i < LeftSum.size(); i++) {
        for(int j = 0; j < B - i - 2;j++) {
                int sumAcross = LeftSum[i] + RightSum[j];
                if(sumAcross > m) {
                    m = sumAcross;
                }
        }
    }
    cout << "Max is: " << m << endl;
    return m;
}

int lengthOfLongestSubstring(string s) {
    string output;
    string substring;
    if(s.length() == 1) return 1;
    for(int i=0; i < s.length(); i++) {
        substring = "";
        substring.push_back(s[i]);
        for(int j=i+1; j < s.length(); j++) {
            if(substring.find(s[j]) != std::string::npos) {
                if(substring.length() > output.length()) {
                    output.assign(substring);
                }
                break;
            }
            substring.push_back(s[j]);
            if(substring.length() > output.length()) {
                output.assign(substring);
            }
        }
    }
    return output.length();
}


int myAtoi(string s) {
    string output;

    int i = 0;

    while(s[i] == 32) {
            i++;
    }
    if(i == s.length()) {
        return 0;
    }
    bool readSign = false;
    while(i < s.length()) {
        if((s[i] == 43 || s[i] == 45) || (s[i] >= 48 && s[i] <= 57)) {
            if(!readSign && (s[i] == 43 || s[i] == 45)) {
                readSign = true;
                output.push_back(s[i]);
                i++;
            } else if((s[i] >= 48 && s[i] <= 57)) {
                output.push_back(s[i]);
                i++;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    if(output.length() == 0) return 0;
    if(output.length() == 1 && (output[0] == '+' || output[0] == '-')) return 0;
    //validation if the value is out of range
    //simple length chk ups
    long int val = 0;
    if(output[0] == '-' || output[0] == '+') {
        if(output.length() - 1 > 10) {
            if(output[0] == '-') {
                val = INT32_MIN;
            } else {
                val = INT32_MAX;
            }
        } else {
            std::string::size_type sz = 1;
            val = stol(output, &sz, 10);
            if(output[0] == '-') {
                if((-val) < INT32_MIN) {
                    val = INT32_MIN;
                }
            } else if(output[0] == '+') {
                if(val > INT32_MAX){
                    val = INT32_MAX;
                }
            }
        }
    } else {
        if(output.length() > 10) {
            val = INT32_MAX;
        } else {
            val = stol(output, nullptr, 10);
            if(val > INT32_MAX) {
                val = INT32_MAX;
            }
        }
    }
    return val;
}


int main() {
        // vector<int>vect{5,-2,3,1,2};
    // cout << Solve(vect, 3) << endl;
    cout << myAtoi("+-12") << endl;
}
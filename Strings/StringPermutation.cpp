#include<iostream>
#define SIZE 4
using namespace std;



void perm(char S[], int k) {
    static int visited[10]{0};
    static char result[10];

    if(S[k] == '\0') {
        result[k] = '\0';
        cout << result << endl;
        return;
    } else {
        for(int i=0; S[i] != '\0'; i++) {
            if(visited[i] == 0) {
                result[k] = S[i];
                visited[i] = 1;
                perm(S, k+1);
                visited[i] = 0;
            }
        }
    }
}

int main() {
    char str[] = "ranveer";
    perm(str, 0);
    return 0;
}
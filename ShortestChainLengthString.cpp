#include<iostream>
#include<queue>
#include<set>
#include<string>
#include<iterator>
using namespace std;

struct QItem {
    string word;
    int len;
};

/*
    - Push first element to Queue
        -  Then while queue is not empty
        -  curr = pop() element
        -  For popped out elements - find out first adjacent node
*/

//to check if string differsy by exactly one character
bool isAdjacentWord(string& a, string& b) {
    int count = 0; //to store count of differences
    int n = a.length();
    for(int i=0; i < n; i++) {
        if(a[i] != b[i]) count++;
        if(count > 1) return false;
        return count == 1 ? true : false;
    }
}

int shortestChainLen(string start, string end, set<string> D) {
    queue<QItem> Q;
    //start distac
    QItem item = {start, 1};
    Q.push(item);

    while(!Q.empty()) {
        QItem curr = Q.front();
        Q.pop();

        for(set<string>::iterator it = D.begin(); it != D.end(); ++it) {
            string temp = *it;
            if(isAdjacentWord(curr.word, temp)) {
                item.word = temp;
                item.len = curr.len + 1;
                Q.push(item);

                D.erase(temp);
                if(temp == end) {
                    return item.len;
                }
            }
        }
    }
    return 0;
}

int main() {
    set<string> D;
    D.insert("poon");
    D.insert("plee");
    D.insert("same");
    D.insert("poie");
    D.insert("plie");
    D.insert("poin");
    D.insert("plea");
    string start = "toon";
    string target = "plea";
    cout << "Length of shortest chain is: "
        << shortestChainLen(start, target, D);
}
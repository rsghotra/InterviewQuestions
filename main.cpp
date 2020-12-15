#include <iostream>
#include <vector>
#include<queue>
#include<array>
using namespace std;
void display(vector<vector<int> >&  matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void BFS(vector<vector<int> > grph, int i) {
    int u,  v;
    queue<int> vtx;
    int* visited = new int[grph.size()](); //initialized with zeros
    cout << "BFS: ";
    cout << i << " ";
    visited[i] = 1;
    vtx.push(i);

    while(!vtx.empty()) {
        u = vtx.front();
        vtx.pop();
        for(int v = 1; v <= grph[0].size(); v++) {
            //check if edge exists and if the edge is not visited
            if(grph[u][v] != 0 && visited[v] == 0) {
                cout << v << " ";
                visited[v] = 1;
                vtx.push(v);
            }
        }
    }
}

int main()
{
    vector<vector<int> > matrix(5, vector<int>(5));
    display(matrix);

    vector<vector<int> > Graph{
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}
    };
    cout << "Displaying Graph" << endl;
    display(Graph);
    BFS(Graph, 1);
    return 0;
}
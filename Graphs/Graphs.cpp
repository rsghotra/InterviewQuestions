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
    int u, v;
    queue<int> vtx;
    int* visited = new int[grph.size()]();
    cout << "BFS: ";
    cout << i << " ";
    vtx.push(i);
    visited[i] = 1;
    while(!vtx.empty()) {
        u = vtx.front();
        vtx.pop();
        for(v = 0; v < grph[0].size(); v++) {
            //check if there is an edge
            if(grph[u][v] == 1 && visited[v] == 0) {
                cout << v << " ";
                visited[v] = 1;
                vtx.push(v);
            }
        }
    }
}

void DFS(const vector<vector<int>>& grph, int u) {
    static int* visited = new int[grph.size()]();
    if(visited[u] == 0) {
        cout << u << " ";
        visited[u] = 1;
        for(int v = 0; v < grph[0].size(); v++) {
            if(grph[u][v] == 1 && visited[v] == 0) {
                DFS(grph, v);
            }
        }
    }
}

void _DFS(const vector<vector<int>>& grph, int u) {
    cout << "\nDFS: ";
    DFS(grph, u);
    cout << endl;
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
        {0, 1, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0}
    };
    cout << "Displaying Graph" << endl;
    display(Graph);
    BFS(Graph, 2);
    _DFS(Graph, 1);
    return 0;
}
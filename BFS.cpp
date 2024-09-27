#include <bits/stdc++.h>
using namespace std;

vector<int> v[1000];
int level[1000];
bool visited[1000]; 
int parent[1000];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    level[src] = 0;
    visited[src] = true; 

    while (!q.empty()) {
        int par = q.front();
        q.pop();

        for (int i = 0; i < v[par].size(); i++) {
            int child = v[par][i];
            if (!visited[child]) {  
                level[child] = level[par] + 1;
                visited[child] = true; 
                parent[child] = par;
                q.push(child);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of edges: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << "Enter root node to traverse: ";
    int src;
    cin >> src;

    // Initializing visited, parent, and level using loops
    for (int i = 0; i < 1000; i++) {
        visited[i] = false;
        parent[i] = -1;
        level[i] = -1;
    }

    bfs(src);

    cout << "Distance of nodes from root:\n";
    for (int i = 0; i < n; i++) {
        if (level[i] != -1) {
            cout << i << " -> " << level[i] << "     ";
        }
    }
    cout << "\nEnter node to see its path from root: ";
    int des;
    cin >> des;

    vector<int> path;
    while (des != -1) {
        path.push_back(des);
        des = parent[des];
    }

    reverse(path.begin(), path.end());

    for (int i : path) {
        cout << i << (i == path.back() ? "\n" : " -> ");
    }

    return 0;
}

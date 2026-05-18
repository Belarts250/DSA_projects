#include<bits/stdc++.h>
using namespace std;

const int N = 100; 
vector<int> tree[N];

void bfs(int root){
    queue<int> q;
    q.push(root);
    cout << "BFS (Level Order Traversal): ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();


        cout << node << " ";


        for (int child : tree[node]) {
            q.push(child);
        }
    }
    cout << endl;

}

int main(){
    int n;
    cin >> n; // num

    int edges;
    cin >> edges; 

    for(int i = 0; i < edges; i++){
        int u, v;

        cin >> u >> v; // parent-child relationship
        tree[u].push_back(v);
    }

    bfs(1);
    return 0;
}

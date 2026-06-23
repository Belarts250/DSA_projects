#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v : adj[u])
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
        }
        cout << "\n";
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> st;
        st.push(start);
        cout << "DFS: ";
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";
                for (int v : adj[u])
                    if (!visited[v]) st.push(v);
            }
        }
        cout << "\n";
    }
};

int main() {
    int V, edges, u, v, start;
    cout << "Enter number of vertices: "; cin >> V;
    Graph g(V);
    cout << "Enter number of edges: "; cin >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Start vertex: "; cin >> start;
    g.BFS(start);
    g.DFS(start);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define V 8

class Prim {
private:
    int graph[V + 1][V + 1];
    int key[V + 1];
    int parent[V + 1];
    bool inMST[V + 1];

    int findMin() {
        int minValue = INT_MAX;
        int index = -1;

        for (int i = 1; i <= V; i++) {
            if (!inMST[i] && key[i] < minValue) {
                minValue = key[i];
                index = i;
            }
        }
        return index;
    }

public:
    Prim(int g[V + 1][V + 1]) {
        for (int i = 0; i <= V; i++)
            for (int j = 0; j <= V; j++)
                graph[i][j] = g[i][j];
    }

    void run() {

        for (int i = 1; i <= V; i++) {
            key[i] = INT_MAX;
            inMST[i] = false;
        }

        key[1] = 0;     
        parent[1] = -1;

        for (int count = 1; count <= V; count++) {

            int u = findMin();
            inMST[u] = true;

            for (int v = 1; v <= V; v++) {
                if (graph[u][v] != 0 && !inMST[v]
                    && graph[u][v] < key[v]) {

                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    void print() {
        int total = 0;

        cout << "Edges in MST:\n";
        for (int i = 2; i <= V; i++) {
            cout << parent[i] << " - " << i
                 << " : " << graph[i][parent[i]] << endl;
            total += graph[i][parent[i]];
        }

        cout << "Total Weight = " << total << endl;
    }
};

int main() {

    int graph[V + 1][V + 1] = {
        {0},
        {0, 0, 0, 47, 0, 80, 54, 0, 0},   
        {0, 0, 0, 55, 31, 32, 0, 74, 79}, 
        {0, 47, 55, 0, 88, 23, 75, 66, 0},
        {0, 0, 31, 88, 0, 0, 74, 0, 29},  
        {0, 80, 32, 23, 0, 0, 0, 93, 0},  
        {0, 54, 0, 75, 74, 0, 0, 0, 0},   
        {0, 0, 74, 66, 0, 93, 0, 0, 68}, 
        {0, 0, 79, 0, 29, 0, 0, 68, 0}    
    };

    Prim p(graph);

    p.run();
    p.print();

    return 0;
}

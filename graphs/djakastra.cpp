#include<iostream>
using namespace std;

const int INF = 1e9;
const int N = 5;

int main(){
	int graph[N][N] = {
		{0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
	}
	
	int dist[N];
	bool visited[N];
	
	for(int i=0; i < N; i++){
		dist[i] = INF;
		visited[i] = false;
	}
	
	int source = 0;
	dist[source] = 0;
	
	for(int i = 0 ; i < N - 1; i++){
		int u = -1;
		for(int j = 0; j < N; j++){
			if(!visited[j] && (u == -1 || dist[j] < dist[u]))
			u = j;
		}
		
		visited[u] = true;
	}
	for(int v = 0; v < N; v++){
            if(graph[u][v] != 0 && !visited[v]){
                if(dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Step 3: Print the shortest distances
    cout << "Shortest distances from node " << source << ":\n";
    for(int i = 0; i < N; i++){
        cout << "Node " << i << " -> " << dist[i] << endl;
    }

    return 0;
}
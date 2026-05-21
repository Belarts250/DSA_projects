#include <bits/stdc++.h>

//Twarimitswe Aaron
//Kamana Clare
//Igihozo Belise

using namespace std;

// Adjacency matrix to represent the graph (7 nodes)
int graph[7][7];

// Array to keep track of visited nodes during BFS
bool visited[7];

// Breadth First Search function
void BFS(int start){
    // Queue to store nodes to be explored
    queue<int> q;
    
    // Mark the starting node as visited
    visited[start]=true;

    // Push the starting node into the queue
    q.push(start);
    
    // Continue until the queue becomes empty
    while(!q.empty()){
        // Get the front node from the queue
        int u=q.front();

        // Remove the front node from the queue
        q.pop(); 
        
        // Print the current node
        cout << u << " ";
        
        // Traverse all possible adjacent nodes
        for(int v=0;v<7;v++){
            // Check if there is an edge and the node is not visited
            if(graph[u][v]==1 && !visited[v]){
                // Mark the node as visited
                visited[v]=true;

                // Add the node to the queue for further exploration
                q.push(v);
            }
        }
    }
    
}

int main(){
    // Temporary adjacency matrix to initialize the graph
    int temp[7][7]= {
        {0,1,1,0,0,0,0}, // Connections for node 0
        {1,0,0,1,1,0,0}, // Connections for node 1
        {1,0,0,0,0,1,0}, // Connections for node 2
        {0,1,0,0,0,0,1}, // Connections for node 3
        {0,1,0,0,0,0,0}, // Connections for node 4
        {0,0,1,0,0,0,0}, // Connections for node 5
        {0,0,0,1,0,0,0}  // Connections for node 6
    };
    
    // Copy values from temp matrix to graph matrix
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            graph[i][j]=temp[i][j];
        }
    }
    
    // Initialize all visited nodes to false (not visited)
    memset(visited, false, sizeof(visited));
    
    // Display message before traversal
    cout << "BFS traversla starting from node 0:\n";

    // Call BFS starting from node 0
    BFS(0);

    return 0;
}
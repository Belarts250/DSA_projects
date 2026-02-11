#include <bits/stdc++.h>

//Twarimitswe Aaron
//Kamana Clare
//Igihozo Belise

using namespace std;

int graph[7][7];
bool visited[7];

void BFS(int start){
	queue<int> q;
	
	visited[start]=true;
	q.push(start);
	
	while(!q.empty()){
		int u=q.front();
		q.pop(); 
		
		cout << u << " ";
		
		for(int v=0;v<7;v++){
			if(graph[u][v]==1 && !visited[v]){
				visited[v]=true;
				q.push(v);
			}
		}
	}
	
}

int main(){
	int temp[7][7]= {
        {0,1,1,0,0,0,0},
        {1,0,0,1,1,0,0},
        {1,0,0,0,0,1,0},
        {0,1,0,0,0,0,1},
        {0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0}
    };
    
    for(int i=0;i<7;i++){
    	for(int j=0;j<7;j++){
    		graph[i][j]=temp[i][j];
		}
	}
	
	memset(visited, false, sizeof(visited));
	
	cout << "BFS traversla starting from node 0:\n";
	BFS(0);
	return 0;
	
	
}
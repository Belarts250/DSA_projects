#include <bits/stdc++.h>
using namespace std;

//Twarimitswe Aaron
//Igihozo Belise
//Kamana Clare

int graph[7][7];
bool visited[7];
void DFS(int start){
	visited[start]=true;
	cout << start;
	
	for(int i=0;i<7;i++){
		if(graph[start][i]==1 && !visited[i]){
			DFS(i);
		}
	}
	
}

int main(){
	    int temp[7][7] = {
        {0,1,1,0,0,0,0},
        {1,0,0,1,1,0,0},
        {1,0,0,0,0,1,0},
        {0,1,0,0,0,0,1},
        {0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0},
        {0,0,0,1,0,0,0}
    };
        for (int i = 0; i < 7; i++)
{
	        for (int j = 0; j < 7; j++)
            {
            	graph[i][j] = temp[i][j];
			}
}

    memset(visited, false, sizeof(visited));
	
	    cout << "DFS traversal starting from node 0:\n";
    DFS(0);
	return 0;
}
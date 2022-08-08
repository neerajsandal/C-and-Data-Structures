#include<iostream>
using namespace std;
void print(int **graph, int vert, int sv, bool* visited)
{
	cout << sv << endl;
	visited[sv] = true;  //  make the visited vertex = 1;
	for(int i = 0; i < vert; i++)
	{
		if(i == sv){
			continue;
		}
		if(graph[sv][i] == 1)
		{
			if(visited[i]){
				continue;
			}
		print(graph,vert,i,visited);
		}
	}
}
void DFS(int **graph, int vert, bool *visited)
{
	for(int  i = 0; i < vert; i++)
	{
		if(visited[i] != true)
			print(graph, vert, i, visited);
	}
}
int main()
{
	int vert, edges;
	cout << "Enter the num of vertices : ";
	cin >> vert;
	
	cout << "Enter the num of edges : ";
	cin >> edges;
	
	// Initialise all values of graph equal to 0;
	int **graph = new int*[vert];
	for(int i = 0; i < vert; i++)
	{
		graph[i] = new int[vert];
		for(int j = 0; j < vert; j++)
			graph[i][j] = 0;
	}
	
	// Enter the vertices corresponds to an edge;
	for(int i = 0; i < edges; i++) 
	{
		int first,end;
		cout << "Starting Vertices : ";
		cin >> first;
		
		cout << "Ending Vertces : ";
		cin >> end;
		graph[first][end] = 1;
		graph[end][first] = 1;
	}
	
	bool *visited = new bool[vert];
	for(int i = 0; i < vert; i++)
		visited[i] = false;  // Initialise all the visited vertices equal to 0; 
		
	cout << "Printing The Graph in DFS Order !!" << endl;
	DFS(graph, vert, visited);
	
	for(int i = 0; i < vert; i++)
		delete graph[i];
	delete []graph;
	delete []visited;
	return 0;
}

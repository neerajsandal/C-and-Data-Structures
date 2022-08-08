#include <iostream>
#include<queue>
using namespace std;
void print(int **graph, int vert,int sv, bool* visited)
{   
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for(int i = 0; i < vert; i++)
        {
            if(i == current)
                continue;
            if(graph[current][i] == 1 && visited[i] != 1)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(int **graph, int vert, bool *visited)
{
	cout << "Printing in BFS order !!" << endl;
    for(int i = 0; i < vert; i++)
    {
		if(visited[i] != true)
        {
            print(graph, vert, i, visited);
        }
    }
}
int main() {
    int vert, edges;
	cout << "Enter the num of vertices : ";
    cin >> vert;
 	cout << "Enter the num of edges : ";
    cin >> edges;
    
    int **graph = new int*[vert];
    for(int i = 0; i < vert; i++)
    {
		graph[i] = new int[vert];
        for(int j = 0; j < vert; j++)
            graph[i][j] = 0;
    }
    
    for(int i = 0; i < edges; i++)
    {
        int sv, ev;
        cin >> sv;
        cin >> ev;
        graph[sv][ev] = 1;
        graph[ev][sv] = 1;
    }
    
    bool* visited = new bool[vert];
    for(int i = 0; i < vert; i++)
        visited[i] = false;
    BFS(graph, vert, visited);
    
    for(int i = 0; i < vert; i++)
		delete graph[i];
	delete []graph;
	delete []visited;
	return 0;
}

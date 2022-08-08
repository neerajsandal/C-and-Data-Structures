/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;
void FindPath(int **arr, int **maze,int row, int col, int n)
{
    if(row == n-1 && col == n-1)
    {
        maze[row][col] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << maze[i][j] << " ";
            }
        }
        cout << endl;
        return ;
    }
    
    /* There are 6 condition that needs to check while making maze[i][j] = 1; 
       1. row != -1          
       2. row < n
       3. col != -1
       4. col < n
       5. arr[i][j] != 0;
       6. maze[i][j] != 1;
    */
    if(row != -1 && row < n && col != -1 && col < n && arr[row][col] != 0 && maze[row][col] != 1)
    {
        maze[row][col] = 1;
        FindPath(arr,maze,row-1,col,n);  // to move up
        FindPath(arr,maze,row+1,col,n);  // to move down
        FindPath(arr,maze,row,col-1,n);  // to move left
        FindPath(arr,maze,row,col+1,n);  // to move right
        maze[row][col] = 0;
    }
}
using namespace std;
int main() {
    int n;
    cin >> n;
    
    int **arr = new int*[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int **maze = new int*[n];
    for(int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            maze[i][j] = 0;
        }
    }
    
    FindPath(arr,maze,0,0,n);
	return 0;
}


/*The standard sudoku puzzle consists of a 9 x 9 grid of cells, 
divided into nine 3x3 blocks. has a unique solution. */
#include<bits/stdc++.h>
#define n 9
using namespace std;
bool isEmpty(int arr[n][n], int &row, int &col)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 0)
            {
                // keeping the row and col updated to find empty position
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafe(int arr[n][n], int row, int col, int num)
{
    // checking the row
    for(int i = 0; i < n; i++)
    {
        if(arr[row][i] == num)
            return false;
    }
    
    // checking the column
    for(int i = 0; i < n; i++)
    {
        if(arr[i][col] == num)
            return false;
    }
    
    // for checking smaller 3*3 box
    int rowfact = row - (row % 3);  
    /* for calculating position of box in which row & col
     so that by adding both factors, we can check whether
     a given no. is present in that box or not */
    int colfact = col - (col % 3);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(arr[i+rowfact][j+colfact] == num)
                return false;
        }
    }
    return true;
}
bool sudoku(int arr[n][n], int row, int col)
{
    bool ans = isEmpty(arr,row,col);
    if(!ans)
    {
        return true; 
    }
    else{
        for(int i = 0; i < n; i++)
        {
            if(isSafe(arr,row,col,i+1))
            {
                arr[row][col] = i+1;
                if(sudoku(arr,row,col))
                   return true;
            }
               arr[row][col] = 0;
        }
    }
    return false;
}
int main(){
    int temp[9];
    int arr[9][9];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    bool ans = sudoku(arr,0,0);
    
    if(ans)
    {
    	cout << "true" << endl;
    	for(int i = 0; i < n; i++)
    	{
        	for(int j = 0; j < n; j++)
            	cout << arr[i][j] << " ";
        	cout << endl;
    	}
	}
    else
        cout << "false" << endl;
    return 0;
}

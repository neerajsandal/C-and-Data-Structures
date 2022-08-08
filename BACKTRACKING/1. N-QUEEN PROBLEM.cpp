#include<bits/stdc++.h>
using namespace std;
bool isPossible(int **arr, int col,int row,int size)
{
    /* we dont need to check all the 8 directions while insertion
    of a queen, we just check all the 3 above directions 
    while inserting, quuens are present only in the array above
    of the given row, and all the rows that are below are empty */
    
    // for cheking of the same column
    for(int i = row-1; i >= 0; i--)
    {
        if(arr[i][col] == 1)
            return false;
    }
    
    // for checking upper left
    for(int i = row - 1,j = col -1 ; i >= 0 && j >= 0; i--,j--)
    {
        if(arr[i][j] == 1)
            return false;
    }
    
    // for checking upper right
    for(int i = row -1 ,j = 0; i >= 0 && j < size; i--,j++)
    {
        if(arr[i][j] == 1)
            return false;
    }
    return true;
}
void placeQueens(int **arr, int size,int row)
{
    if(row == size)
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
                cout << arr[i][j] << " ";
        }
        cout << endl;
        return;
    }
    for(int j = 0; j < size; j++)
    {
        if(isPossible(arr,j,row,size))
        {
            arr[row][j] = 1;
            placeQueens(arr,size,row+1);  // for the next row
            arr[row][j] = 0;
        }
    }
}
int main(){
    int size;
    cin >> size;
    // Create a 2-D array dynamically
    int **arr = new int*[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
        for(int j = 0; j < size; j++)
            arr[i][j] = 0;
    }
    
    placeQueens(arr,size,0);
    delete []arr;
    return 0;
}

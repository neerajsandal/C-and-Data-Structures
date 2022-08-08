#include <iostream>
using namespace std;
#include<cmath>
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    if(n == 0 && m == 0)
        return 0;
	int **ans = new int*[n];
    for(int i = 0; i < n; i++)
    {
        ans[i] = new int[m];
    }
    
    //enter the value of maximum sized sq natrix
    //corresponds to given index in the ans array;
    
    for(int i = 0; i < n; i++) // for 1st col
    {
        if(arr[i][0] == 1){
            // if arr[i][j] = 1; no sq. matrix can be formed
            ans[i][0] = 0;
        }
        else
            ans[i][0] = 1;
    }
    
    for(int i = 0; i < m; i++) // for 1st row
    {
        if(arr[0][i] == 1)
            ans[0][i] = 0;
        else
            ans[0][i] = 1;
    }
    
    int max = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            int a1 = ans[i-1][j-1];
            int a2 = ans[i][j-1];
            int a3 = ans[i-1][j];
            ans[i][j] =  1 + min(a1,min(a2,a3));
            
            if(max < ans[i][j])
                max = ans[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
			cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return max;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}

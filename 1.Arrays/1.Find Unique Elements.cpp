#include <iostream>
#include<climits>
int findUnique(int *arr, int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i!=j)
            {
                if(arr[i]==arr[j]&&arr[i]!=INT_MIN)
                {
                    arr[j]=INT_MIN;  
                    arr[i]=INT_MIN;
                }
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=INT_MIN)
        {
            return arr[i];
        }
    }
    
}
using namespace std;

int main()
{

	int t;
	cin >> t;

	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		cout << findUnique(input, size) << endl;
	}

	return 0;
}

/*
Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1


Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
4
10
*/

#include <iostream>
#include<climits>
using namespace std;
int duplicateNumber(int *arr, int size)
{
	int dup;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i!=j)
            {
                if(arr[i]==arr[j] &&arr[i]!=INT_MIN)
                {
                	 dup=arr[i];
                     arr[i]=INT_MIN;
                     arr[j]=INT_MIN; 
					 return dup;    
                }
            }
        }
    }
}

int main()
{

	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << duplicateNumber(input, size) << endl;
	}

	return 0;
}

/*
Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6
Sample Output 1:
7


Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2
Sample Output 2:
1
3
*/

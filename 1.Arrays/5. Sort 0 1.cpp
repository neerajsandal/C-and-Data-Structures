#include <iostream>
#include <algorithm>
using namespace std;

void sortZeroesAndOne(int *input, int size)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(input[i]==0)
        count++;
    }
    for(int i=0;i<count;i++)
    {
        input[i]=0;
    }
    for(int i=count;i<size;i++){
        input[i]=1;
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		sortZeroesAndOne(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}

/*
2
8    // size of an array
1 0 1 1 0 1 0 1
5    // size of array
0 1 0 1 0
Sample Output :
0 0 0 1 1 1 1 1
0 0 0 1 1 
*/

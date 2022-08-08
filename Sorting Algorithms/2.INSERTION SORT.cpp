#include<iostream>
using namespace std;
int main()
{
	int size;
	cout << "Enter the size of an array: ";
	cin>>size;
	int *arr = new int[size];
	for(int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	int i,j;
	for(i = 1; i < size; i++)
	{
		int max = arr[i];
		for(j = i-1; j >= 0; j--)
		{
			if(max < arr[j])
			{
				arr[j+1] = arr[j];
			}
			else
			break;
		}
		arr[j+1] = max;
	}
	cout << "Sorted Array !! " <<endl;
	for(int i = 0; i < size; i++)
	{
	    cout << arr[i] << "  ";
	}
	cout << endl;
}

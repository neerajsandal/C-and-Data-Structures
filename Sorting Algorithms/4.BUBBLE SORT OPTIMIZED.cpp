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
	for(int i = 1; i < size; i++)
	{
		int flag = 0;
		for(int j = 0; j < size-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				flag++;
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
		if(!flag)
		{
			break;
		}
	}
	cout << "Sorted Array !! " <<endl;
	for(int i = 0; i < size; i++)
	{
	    cout << arr[i] << "  ";
	}
	cout << endl;
}

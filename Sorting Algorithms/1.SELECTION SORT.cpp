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
	// by taking the last element as the maximum element;
//	for(int i = size-1; i>=0; i--)
//	{
//		for(int j = i-1; j>=0; j--)
//		{
//			if(arr[i] < arr[j])
//			{
//				int temp1 = arr[j];
//				arr[j] = arr[i];
//				arr[i] = temp1;
//			}
//		}
//	}
    // another way
    for(int i = size-1; i >= 0; i--)
    {
    	int max =  i;
    	for(int j = i - 1; j >= 0; j--)
    	{
    		if(arr[max] < arr[j])
    		max = j;
		}
		int temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}
	cout << "Sorted Array !! " <<endl;
	for(int i = 0; i < size; i++)
	{
	    cout << arr[i] << "  ";
	}
	cout << endl;
}

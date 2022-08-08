#include<iostream>
using namespace std;
void mergesort(int *&arr,int first,int last)
{
	
}
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
	mergesort(arr,0,size-1);
	cout << "Sorted Array !! " <<endl;
	for(int i = 0; i < size; i++)
	{
	    cout << arr[i] << "  ";
	}
	cout << endl;
}

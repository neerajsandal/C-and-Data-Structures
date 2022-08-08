#include<iostream>
using namespace std;
int partition(int *arr, int p, int r)
{
	int x = arr[r]; // last element as pivot element
	int i = p-1;
	for(int j = p; j < r; j++)
	{
		if(arr[j] <= x)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}
void QuickSort(int *arr, int p, int r)
{
	if(p < r)
	{
		int q = partition(arr, p, r);
		QuickSort(arr, p, q-1);
		QuickSort(arr, q+1, r);
	}
}
int main()
{
	int arr[] = {2,5,4,7,1,3,2,6};
	QuickSort(arr, 0, 7);
	
	for(int i = 0; i <= 7; i++)
	{
		cout << arr[i] << " ";
	}
}

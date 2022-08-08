#include<iostream>
using namespace std;
int partition(int *arr, int p, int r)
{
	int x = arr[r];
	int i = p-1;
	for(int j = p; j < r; j++)
	{
		if(arr[j] <= x)
		{
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = temp;
	return i+1;
}
//void QuickSort(int *arr, int p, int r)
//{
//	if(p < r)
//	{
//		int q = partition(arr, p, r);
//		QuickSort(arr, p, q-1);
//		QuickSort(arr, q+1, r);
//	}
//}
void QuickSort(int *arr, int n)
{
	int beg[n];
	int end[n];
	
	int i = 0; 
	beg[0] = 0; end[0] = n-1;
	while(i>= 0)
	{
		int p = beg[i];
		int r = end[i];
		i--;
		
		int q = partition(arr, p, r);
		if(q-1 > p)
		{
			i++; 
			beg[i] = p;
			end[i] = q-1;
		}
		if(q+1 < r)
		{
			i++;
			beg[i] = q+1;
			end[i] = r;
		}
	}
}
int main()
{
	int arr[] = {2,5,4,7,1,3,2,6};
	QuickSort(arr,7);
//	QuickSort(arr, 0, 7);
	for(int i = 0; i <= 7; i++)
	{
		cout << arr[i] << " ";
	}
}

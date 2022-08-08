#include<iostream>
using namespace std;
void Merge(int *arr, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-(q+1)+1;
	
	int L[n1], R[n2];
	for(int i = 0; i < n1; i++)
	{
		L[i] = arr[p+i];
	}
	
	for(int i = 0; i < n2; i++)
	{
		R[i] = arr[q+1+i];
	}
	
	int i = 0; int j = 0; int k = p;
	while(i <n1 and j < n2)
	{
		if(L[i] <= R[j])
		arr[k++] = L[i++];
		
		else
		arr[k++] = R[j++];
	}
	
	while(i < n1)
	{
		arr[k++] = L[i++];
	}
	while(j < n2)
	{
		arr[k++] = R[j++];
	}
}
MergeSort(int *arr, int p, int r)
{
	if(p < r)
	{
		int q = (p+r)/2;
		MergeSort(arr, p,q);
		MergeSort(arr,q+1, r);
		Merge(arr, p, q, r);
	}	
}
int main()
{
	int arr[] = {2,5,4,7,1,3,2,6};
	MergeSort(arr, 0, 7);
	
	for(int i = 0; i <= 7; i++)
	{
		cout << arr[i] << " ";
	}
}

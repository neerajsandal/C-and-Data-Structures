#include<iostream>
#include<climits>
using namespace std;
void Max_Heapify(int *arr, int i, int size)
{
	int largest = i;
	int left = (2*i);
	int right = (2*i) + 1;
	
	if(left <= size && arr[left] > arr[largest] )
	largest = left;
	
	if(right <= size && arr[right] > arr[largest])
	largest = right;
	
	if(largest != i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		Max_Heapify(arr,largest,size);
	}
}
void Build_Heap_Max(int *arr, int heap_size)
{
	for(int i = heap_size/2; i >= 1; i--)
	{
		Max_Heapify(arr,i,heap_size);
	}
}
int Heap_Extract_Max(int *arr, int size)
{
	if(size < 1)
	{
		cout << "Heap Underflow " << endl;
		return INT_MIN;
	}
	int max = arr[1];
	arr[1] = arr[size];
	size = size - 1;
	Max_Heapify(arr,1,size);
	return max;
}
void print(int *arr,int n)
{
	for(int i = 1; i <= n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
int main()
{
    int n;
	cout << "Enter the size of an heap : ";
	cin >>n;
	int *arr = new int[100];
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	Build_Heap_Max(arr,n);
	print(arr,n); 
	int max = Heap_Extract_Max(arr,n);
	cout << "MAX.. IS : " << max << endl;
	delete [] arr;
}

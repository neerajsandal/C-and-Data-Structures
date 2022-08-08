// HEAP is used for the Complete Binary Tree
#include<iostream>
using namespace std;

void MAX_HEAPIFY(int *arr, int i, int heap_size)
{
	int largest = i;
	int l = 2*i;
	int r = (2*i) + 1;
	
	if(l <= heap_size && arr[l] > arr[largest])
    largest = l;
    
    if(r <= heap_size && arr[r] > arr[largest])
    largest = r;
    
    if(largest != i)
    {
    	int temp = arr[i];
    	arr[i] = arr[largest];
    	arr[largest] = temp;
    	MAX_HEAPIFY(arr,largest,heap_size);
	}
}
void BUILD_MAX_HEAP(int *arr, int n)
{
	int heap_size = n;
	for(int i = (heap_size/2); i >=1; i--)
	{
		MAX_HEAPIFY(arr,i,heap_size);
	}
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
	BUILD_MAX_HEAP(arr,n);
	
	int heap_size = n;
	cout << "\n ARRAY AFTER BUILD HEAP MAX " << endl;
	print(arr,n);
	for(int i = n; i >= 2; i--)
	{
		int temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		
		heap_size--;
		MAX_HEAPIFY(arr,1,heap_size);
	}
	cout << "\n SORTED ARRAY" << endl;
	print(arr,n);
	delete [] arr;	
}
// 16 4 10 14 7 9 3 2 8 1
// 5 3 17 10 84 19 6 22 9 

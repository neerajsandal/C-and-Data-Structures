#include<iostream>
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
void print(int *arr,int n)
{
	for(int i = 1; i <= n; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}
void Heap_Increase_Key(int *arr, int i,int  key)
{
	if(key < arr[i])
	{
		cout << "New Key is Smaller than Current Key " << endl;
		return ;
	}
	arr[i] = key;
	int parent = i/2;
	while( i > 1 && arr[parent] < arr[i])
	{
		int temp = arr[parent];
		arr[parent] = arr[i];
		arr[i] = temp;
		i = parent;
		parent = i/2;
	}	
}
void Max_Heap_Insert(int *arr,int &heap_size, int key)
{
	heap_size++;
	arr[heap_size] = INT_MIN;
	Heap_Increase_Key(arr,heap_size,key);
}
int main()
{
    int n;
	cout << "Enter the HeapSize : ";
	cin >>n;
	int *arr = new int[100];
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	Build_Heap_Max(arr,n);
	print(arr,n);
    
    int key;
    cout << "Enter the key that u want to insert : ";
    cin >> key;
	Max_Heap_Insert(arr,n,key);

	print(arr,n);
	delete [] arr;
}

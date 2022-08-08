// Binary Search Iterative
#include<iostream>
using namespace std;
int main()
{
    int n;
	cout << "Enter the size of an array : ";
	cin >> n;
	
	int *arr = new int[n];
	cout << "Input the array in sorted form" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}	
	int start = 0;
	int end = n-1;
	
	int element;
	cout << "Enter the element that u want to search : ";
	cin >> element;
	
	int flag = -1;
	while(start <= end)
	{
		int middle = (start + end)/2;
		if(arr[middle] > element)
		{
			end = middle-1;
		}
		else if (arr[middle] < element)
		{
			start = middle+1;
		}
		else {
			flag = middle+1;
			break;
		}
	}
	if(flag == -1)
	{
		cout << "NOT FOUND !!! " << endl;
	}
	else{
		cout << "FOUND !!!   at POS : " << flag << endl;
	}
}




// Binary Search Recursive
#include<iostream>
using namespace std;
int binary_search(int arr[], int start,int end,int key)
{
	if(start > end)
	{
		return -1;		
	}
	else{
		int mid = (start+end)/2;
		
		if(key < arr[mid])
		return binary_search(arr,start,mid-1,key);
		
		else if(key > arr[mid])
		return binary_search(arr,mid+1,end,key);
		
		else if(key == arr[mid])
		return mid;
	}
}
int main()
{
    int n;
	cout << "Enter the size of an array : ";
	cin >> n;
	
	int *arr = new int[n];
	cout << "Input the array in sorted form" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}	
	int start = 0;
	int end = n-1;
	
	int key;
	cout << "Enter the element that u want to search : ";
	cin >> key;
	int c = binary_search(arr,start,end,key);
	
	if(c == -1)
	cout << "Not Found !! " << endl; 
	else
	cout << "Found !!  at POS : " << c+1 << endl;
}


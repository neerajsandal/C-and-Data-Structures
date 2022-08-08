// FIBONACCI SERIES
// with recursion, time comp --> O(2^n)
// with memoization(generally recursive), time comp --> O(n)
#include<iostream>
using namespace std;
int fibo_helper(int *arr,int n)
{
	if(n <= 1)
	   return n;
	if(arr[n] != -1)
		return arr[n];
	
	int a = fibo_helper(arr,n-1);
	int b = fibo_helper(arr,n-2);
	
	// store the calculated value of fibo(n) at arr[n];
	arr[n] = a+b;
	return arr[n];
}
int fibo(int n)
{
	int *arr = new int[n+1];  //create a dynamic array of size 'n+1' 
	for(int i = 0; i < n+1; i++)
	{
		arr[i] = -1;
	}
	fibo_helper(arr,n);
}
int main()
{
	int n;
	cout << "Enter the fibonacci number u want to find : ";
	cin >> n;
	cout << " ans : " << fibo(n);
	return 0;
}

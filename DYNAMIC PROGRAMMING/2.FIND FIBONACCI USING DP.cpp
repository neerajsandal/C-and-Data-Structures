// DYNAMIC PROGRAMMING OF FIBONACCI SERIES
// (Generally Iterative approach) time comp --> O(n)
#include<iostream>
using namespace std;
int fibo(int n)
{
	int *ans = new int[n+1];  //create a dynamic array of size 'n+1' 
	ans[0] = 0;
	ans[1] = 1;
	
	for(int i = 2; i <= n; i++)
		ans[i] = ans[i-1] + ans[i-2];
	return ans[n];
}
int main()
{
	int n;
	cout << "Enter the fibonacci number u want to find : ";
	cin >> n;
	cout << " ans : " << fibo(n);
	return 0;
}

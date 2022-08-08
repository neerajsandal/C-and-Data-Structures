#include <iostream>
using namespace std;
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	if(n == 0 || maxWeight == 0)
        return 0;
    /* if weight[0] is greater than the maxweight, then simply go to the 
    next element of an array without reducing maxweight */ 
    if(weights[0] > maxWeight)
        return knapsack(weights+1,values+1,n-1,maxWeight);
    
    // add the values to 'a' and reducing the maxweight by maxweight - weights[0]
    int a = values[0] + knapsack(weights+1,values+1,n-1,maxWeight-weights[0]);
    int b = knapsack(weights+1,values+1,n-1,maxWeight);
    return max(a,b);
}

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}

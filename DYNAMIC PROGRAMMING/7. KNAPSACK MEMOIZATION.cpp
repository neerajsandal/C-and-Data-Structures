//Memoization
#include <cstring>
#include <iostream>
using namespace std;

 int knapsack(int* weight, int* value, int n, int maxWeight,int **dp) {
 	if(n == 0 || maxWeight == 0)
         return 0;
     if(dp[n][maxWeight] != -1)
         return dp[n][maxWeight];
     if(weight[0] > maxWeight)
     {
         dp[n][maxWeight] = knapsack(weight+1, value+1, n-1, maxWeight,dp);
     	return dp[n][maxWeight];
     }
     int a = knapsack(weight+1, value+1, n-1, maxWeight,dp);
     int b = value[0] + knapsack(weight+1, value+1, n-1, maxWeight-weight[0],dp);
    
     dp[n][maxWeight] = max(a,b);
     return max(a,b);
 }
 int knapsack(int* weight, int* value, int n, int maxWeight)
 {
     int **dp = new int*[n+1];
     for(int i = 0; i <= n; i++)
     {
         dp[i] = new int[maxWeight+1];
         for(int j = 0; j <= maxWeight; j++)
             dp[i][j] = -1;
     }
     return knapsack(weight,value,n,maxWeight,dp);
		
     for(int i = 0; i <= n; i++)
 		delete dp[i];
     delete []dp;
 }

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}

// Dynamic Progg. ---> best approach
#include <cstring>
#include <iostream>
using namespace std;

int knapsack(int* weight, int* value, int n, int maxWeight)
{
    if(n == 0 || maxWeight == 0)
         return 0;
 
    int **dp = new int*[n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[maxWeight+1];
        for(int j = 0; j <= maxWeight; j++)
            dp[i][j] = -1;
    }
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= maxWeight; j++)
        {
            if(i == 0 || j == 0)  // base case of recursion
                dp[i][j] = 0;
            
            else if(weight[i-1] > j) // when weight > maxWeight
            {
                dp[i][j] = dp[i-1][j];
            }
            else{
                int a1 = dp[i-1][j]; // if value is not included
                int a2 = value[i-1] + dp[i-1][j - weight[i-1]];
                dp[i][j] = max(a1,a2);
            }
        }
    }
    return dp[n][maxWeight];
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

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int lcs(string s1, string s2)
{
	int m = s1.size();
	int n = s2.size();
	int **ans = new int*[m+1];
	for(int i = 0; i <= m; i++)
	{
		ans[i] = new int[n+1];
	}
	
	// first col = 0
	for(int i = 0; i <= m; i++)
		ans[i][0] = 0;
	// first row = 0;
	for(int i = 0; i <= n; i++)
		ans[0][i] = 0;
	
	// Dynamic Programming
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(s1[m-i] == s2[n-j])
				ans[i][j] = 1 + ans[i-1][j-1];
			else{
				int a = ans[i-1][j];
				int b = ans[i][j-1];
				int c = ans[i-1][j-1];
				ans[i][j] = max(a,max(b,c));
			}
		}
	}
	return ans[m][n];
}
int main()
{
	cout << "Enter two strings !! "<< endl;
	string s1,s2; 
	cin >> s1 >> s2;
	int c = lcs(s1,s2);
	cout << "largest common substring : " << c << endl;
}
/*abcdefjkdjsl
sdjijcnskjkdos*/

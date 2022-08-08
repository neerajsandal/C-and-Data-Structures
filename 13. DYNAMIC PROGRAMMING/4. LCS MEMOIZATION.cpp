#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int lcs(string s1, string s2,int **output)
{
	// base case
	if(s1.size() == 0 || s2.size() == 0)
	   return 0;
	// check
	int m = s1.size();
	int n = s2.size();
	if(output[m][n] != -1)
		return output[m][n];
	// recursive calls
	int ans;
	if(s1[0] == s2[0])
	   ans = 1 + lcs(s1.substr(1),s2.substr(1),output);
	else{
		int c1 = lcs(s1.substr(1),s2,output);
		int c2 = lcs(s1,s2.substr(1),output);
		int c3 = lcs(s1.substr(1),s2.substr(1),output);
		ans = max(c1,max(c2,c3)); 
	}  
	output[m][n] = ans;
	return ans; 
}
int lcs_mem(string s1, string s2)
{
	int m = s1.size();
	int n = s2.size();
	int **ans = new int*[m+1];
	for(int i = 0; i <= m; i++)
	{
		ans[i] = new int[n+1];
		for(int j = 0; j <= n; j++)
		{
			ans[i][j] = -1;
		}
	}
	return lcs(s1,s2,ans);
}
int main()
{
	cout << "Enter two strings !! "<< endl;
	string s1,s2; 
	cin >> s1 >> s2;
	int c = lcs_mem(s1,s2);
	cout << "largest common substring : " << c << endl;
}

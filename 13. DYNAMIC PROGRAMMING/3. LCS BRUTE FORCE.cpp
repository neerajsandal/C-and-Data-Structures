#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int lcs(string s1, string s2)
{
	// base case
	if(s1.size() == 0 || s2.size() == 0)
	   return 0;
	
	// recursive calls
	if(s1[0] == s2[0])
	   return 1 + lcs(s1.substr(1),s2.substr(1));
	else{
		int c1 = lcs(s1.substr(1),s2);
		int c2 = lcs(s1,s2.substr(1));
	//	int c3 = lcs(s1.substr(1),s2.substr(1));
	//	return max(c1,max(c2,c3)); 
	    return max(c1,c2);
	}   
}
int main()
{
	cout << "Enter two strings !! "<< endl;
	string s1,s2; 
	cin >> s1 >> s2;
	int c = lcs(s1,s2);
	cout << "largest common substring : " << c << endl;
}

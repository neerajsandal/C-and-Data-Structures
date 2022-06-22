#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool isValid(string str)
{
	bool ans = true;
	int n = str.length();
	stack<char> stak; 
	for(int i = 0; i < n; i++ )
	{
		if(str[i] == '[' || str[i] == '{' || str[i] == '(' )
		{
			stak.push(str[i]);
		}
		else if(str[i] == ']')
		{
			if(!stak.empty() && stak.top() == '[')
			stak.pop();
			else{
				ans = false;
				break;
			}
		}
		else if(str[i] == '}')
		{
			if(!stak.empty() && stak.top() == '{')
			stak.pop();
			else{
				ans = false;
				break;
			}
		}
		else if(str[i] == ')')
		{
			if(!stak.empty() && stak.top() == '(')
			stak.pop();
			else{
				ans = false;
				break;
			}
		}
	}
	if(!stak.empty())
	return false;
	else
	return ans;
}

bool check(bool ans)
{
	if(ans == true)
	cout << "valid " << endl;
	else
	cout << "not valid " << endl;
}
int main()
{
	string str = "[{()}]"; // valid 
	bool ans = isValid(str);
    check(ans);
	 
	string str1 = "[{()]}"; // invalid 
	ans = isValid(str1);
    check(ans);
	
	string str2 = "({[]}";  // stack not empty so invalid
	ans = isValid(str2);
    check(ans);
    
    string str3 = "({[]})}";  
	ans = isValid(str3);
    check(ans);
}

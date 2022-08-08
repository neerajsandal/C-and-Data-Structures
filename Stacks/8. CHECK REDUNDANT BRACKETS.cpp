/*
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets
and the output will be 'true'.
*/
#include <iostream>
#include <string>
#include<stack>
using namespace std;
bool checkRedundantBrackets(string exp) {
    stack<char> s;
    for(int i = 0; i < exp.size(); i++)
    {
        s.push(exp[i]);
    }
    int count;
    while(!s.empty())
    {
        if(s.top()==')')
        {
            count = 0;
            s.pop();
        }
        else if(s.top()=='(' && count>1)
        {
            count = 0;
            s.pop();
        }
        else if(s.top()=='(' && count <=1)
        {
            return true;
        }
        else{
            count++;
            s.pop();
        }
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}

/*
Sample Input 1:
a+(b)+c 
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.


Sample Input 2:
(a+b)
Sample Output 2:
false
*/

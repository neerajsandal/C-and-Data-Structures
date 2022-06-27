/*
Minimum bracket Reversal

For a given expression in the form of a string, find the minimum number of brackets 
that can be reversed in order to make the expression balanced. The expression will 
only contain curly brackets.
If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, 
the whole expression will get balanced. Since we have to reverse two brackets
to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, 
we would be left with the first opening bracket and hence will not be 
able to make the expression balanced and the output will be -1.
*/

#include <iostream>
#include <string>
using namespace std;
#include<bits/stdc++.h>
#include<stack>
int countBracketReversals(string input) {
	// Write your code here
    int len = input.length();
 
    // length of expression must be even to make
    // it balanced by using reversals.
    if (len%2)
       return -1;
 
    // After this loop, stack contains unbalanced
    // part of expression, i.e., expression of the
    // form "}}..}{{..{"
    stack<char> s;
    for (int i=0; i<len; i++)
    {
        if (input[i]=='}' && !s.empty())
        {
            if (s.top()=='{')
                s.pop();
            else
                s.push(input[i]);
        }
        else
            s.push(input[i]);
    }
 
    // Length of the reduced expression
    // red_len = (m+n)
    int red_len = s.size();
 
    // count opening brackets at the end of
    // stack
    int n = 0;
    while (!s.empty() && s.top() == '{')
    {
        s.pop();
        n++;
    }
 
    // return ceil(m/2) + ceil(n/2) which is
    // actually equal to (m+n)/2 + n%2 when
    // m+n is even.
    return (red_len/2 + n%2);
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
/*
Sample Input 1:
{{{
Sample Output 1:
-1


Sample Input 2:
{{{{}}
Sample Output 2:
1
*/

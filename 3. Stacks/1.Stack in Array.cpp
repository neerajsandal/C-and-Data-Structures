#include<iostream>
using namespace std;
#define n 100
class stack{
	int *arr;
	int top;
	
	public:
		stack()
		{
			arr = new int [n];
			top = -1;
		}
		void push(int x)
		{
			if(top == n-1)
			{
				cout<<"stack overflow"<<endl;
			}
			top++;
			arr[top] = x;
		}
		
		void pop()
		{
			top--;
			if(top == -1)
			{
				cout<<" Stack is Empty"<<endl;
				return ;
			}
		}
		int top()
		{
			if(top==n-1)
			{ 
			   cout<<"Stack is Empty "<<endl;
			   return -1;
		    }
			else
			return arr[top];
		}
};
int main()
{
	stack st;
	st.push(10);
	st.push(20);
	st.push(23);
	st.pop();
	st.top();
	st.pop();
	st.top();
	st.pop();
	st.pop();
}

#include<iostream>
#include<stack>
using namespace std;

void insert_bottom(stack<int> &st,int element)
{
	if(st.empty())
	{
	    st.push(element);
		return;	
    }	
    int top_ele = st.top();
    st.pop();
    insert_bottom(st,element);
    
    st.push(top_ele);
}
void reverse(stack<int> &st){
	if(st.empty())
	return;
	
	int element = st.top();
	st.pop();
	reverse(st);
	insert_bottom(st,element);
}
void display(stack<int> &st)
{
	while(!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	cout<<endl;
}
int main()
{
	stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	
	cout<<"\n REVERSE STACK... \n"<<endl;
	reverse(st);
	display(st);
}

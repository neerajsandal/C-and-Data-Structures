#include<iostream>
using namespace std;
class stack{
	int *arr;
	int top;
	int n; // capacity of an array
	public:
		stack init(int x)
		{
			top = -1;
			n = x;
			arr = new int[n];
		}
		void print()
		{
			for(int i = top;i>=0;i--)
			cout<<arr[i]<<"  ";
			cout<<endl;
		}
		bool isFull()
		{
		   return(top == n-1);
		}
		bool isEmpty()
		{
			return(top == -1);
		}
		
		void push(int x)
		{
			if(isFull())
			cout<<"Stack overflow"<<endl;
			else
			{
				top ++;
				arr[top] = x;
			}	
		}
		void pop()
		{
			if(isEmpty())
			cout<<"NO ELEMENT PRESENT"<<endl;
			else
			top--;
		}
		void Top()
		{
			if(isEmpty())
			cout<<"NO ELEMENT PRESENT"<<endl;
			else
			cout<<"top element is "<<arr[top]<<endl;
		}
};
int main()
{
	stack s;
	s.init(10);
	if(s.isEmpty())
	cout << "Empty "<< endl;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(10);
	s.push(20);
	s.push(30);
	s.print();
	s.pop();
	s.Top();
	s.push(27);
	if(s.isFull())
	cout<<"Full"<<endl;
	
	s.push(56);
	s.Top();
	s.pop();
	s.push(23);
	s.print();
}

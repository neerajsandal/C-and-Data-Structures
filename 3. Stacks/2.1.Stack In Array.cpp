#include<iostream>
using namespace std;
class stack{
	int *arr;
	int top;
	int n; // capacity of an array
	public:
		stack init()
		{
			top = -1;
			n = 4;
			arr = new int[4];
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
		
//		void push(int x)
//		{
//			if(top==n-1)
//			{
//				int *newarr = new int[2*n];
//				for(int i = 0;i < n;i++)
//				{
//					newarr[i] = arr[i];
//				}
//				n *= 2;
//				delete [] arr;
//				arr = newarr;
//			}
//			top++;
//			arr[top] = x;
//		}
        void push(int x)
		{
			if(top == n-1)
			{
				int *newarr = new int[2*n];
				for(int i = 0; i < n ; i++)
				{
					newarr[i] = arr[i];
				}
				delete [] arr;
				arr = newarr;
				n *= 2;
			}
			top++;
			arr[top] = x;
		}
//        void push(int x)
//{
//	if(top == n-1)
//	{
//		int *newarr = new int[2*n];
//		for(int i = 0; i < n; i++)
//		{
//			newarr[i] = arr[i];
//		}
//		delete [] arr;
//		arr = newarr;
//		n *= 2;
//	}
//	top++;
//	arr[top] = x;
//}
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
	s.init();
	if(s.isEmpty())
	cout << "Empty "<< endl;
	
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

#include<iostream>
using namespace std;
class node{
	int top;
	node *head = NULL;
	node *next;
	public :
	node init()
	{
		next = NULL;
	}
	bool isEmpty()
	{
		if (next == NULL)
		return true;
		else
		return false;
	}
	void push(int x) // insert at head
	{
		node *temp = new node;
		temp->top = x;
		temp->next = head;
		head = temp; 
	}
	 void pop()   // delete at head
	 {
	 	if(head == NULL)
	 	cout<<"delete not possible "<<endl;
	 	else if(head->next == NULL)
	    head=NULL;
	    else
	    {
	    	node *temp = head;
	    	delete temp;
	    	head = head->next;
		}
	 }
	 void peek()
	 {
	 	if(head)
	 	cout << "top is "<< head->top << endl;
	 }
	 void display()
	 {
	 	node *temp = head;
	    while(temp)
	    {
	    	cout << temp->top << "  ";
	    	temp = temp->next;
		}
	 }
};

int main()
{
	node st;
	st.init();
	if(st.isEmpty())
	cout << "Stack is Empty"<<endl;
	
	st.push(35);
	st.push(45);
	st.push(27);
	st.display();
	
	st.peek();
	st.pop();
	
	st.peek();
	st.pop();
}

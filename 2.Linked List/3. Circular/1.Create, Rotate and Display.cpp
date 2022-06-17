#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;
void create()
{
	int num;
	cout<<"Enter the elements to be added ";
	cin>>num;
	while(num!=0)
	{
		node *temp=new node;
		cin>>temp->data;
		temp->next=temp;
		if(head==NULL)
		head=temp;
		else{
			node *temp1=head;
		    while(temp1->next!=head)
			temp1=temp1->next;
			
			temp1->next=temp;
			temp->next=head;	
		}
		num--;
	}
}
void display()
{
	if(head==NULL)
	cout<<"CIRCULAR LINKED LIST IS EMPTY"<<endl;
	
	else{
	node *temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	   cout<<temp->data<<endl;
	}
}
void rotate()
{
	if(head==NULL)
	cout<<"NO rotation bcz LIST IS EMPTY"<<endl;
	else{
		int num,count=0;
		cin>>num;
		node *temp=head;
		while(temp->next!=head &&count!=num)
		{
			count++;
		    temp=temp->next;
		}
		head=temp;
	}
}
int main()
{
	create();
	display();
	rotate();
	display();
}

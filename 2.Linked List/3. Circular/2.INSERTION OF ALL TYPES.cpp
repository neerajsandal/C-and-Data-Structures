#include<iostream>
using namespace std;
struct node{
	int data;
	struct node *next;
};
node *head=NULL;
void create()
{
	int num;
	cout<<"Enter the size ";
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
void insert_at_begin()
{
	cout<<"Enter the element to be insert at begin ";
	node *temp=new node;
	cin>>temp->data;
	temp->next=temp;
	
	if(head==NULL)
	head=temp;
	else{
		temp->next=head;
		node *temp1=head;
		while(temp1->next!=head)
		temp1=temp1->next;
		
		temp1->next=temp;
	    head=temp;
	}
}
void insert_at_end()
{
	cout<<"Enter the element to be insert at end ";
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
}
void insert_at_mid()
{
	if(head==NULL)
	cout<<"INSERTION IS NOT POSSIBLE "<<endl;
	else {
		int nod;
	    cout<<"Enter the node after which u want to insert ";
	    cin>>nod;
	    cout<<"Enter the element ";
	    node *temp=new node;
	    cin>>temp->data;
	    temp->next=temp;
	
		node *temp1=head;
		while(temp1->next!=head && temp1->data!=nod)
		temp1=temp1->next;
		
		if(temp1->data==nod)
		{
			temp->next=temp1->next;
			temp1->next=temp;
		}
		else
			cout<<"INSERTION IS NOT POSSIBLE "<<endl;	
    }
}
int main()
{
	while(1){
		int ch;
		cout<<"Enter your choice \n1.CREATE\n2.DISPLAY\n3.INSERT AT BEGIN\n4.INSERT AT END\n5.INSERT AT MID\n"<<endl;
		cin>>ch;
		switch(ch){
			case 1:create();break;
			case 2:display();break;
			case 3:insert_at_begin();break;
			case 4:insert_at_end();break;
			case 5:insert_at_mid();break;
			default: display();return 0;
		}
	}
}

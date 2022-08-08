#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
struct node *head=NULL;
void create()
{
	int num;
	cout<<"enter the size ";
	cin>>num;
	while(num!=0)
	{
		node *temp=new node;
		cin>>temp->data;
		temp->next=temp;
		
		if(head==NULL)
		head=temp;
		else{
			node *upu=head;
			while(upu->next!=head)
			upu=upu->next;
			
			upu->next=temp;
			temp->next=head;
		}
		num--;
	}
}
void display()
{
	if(head==NULL)
	cout<<"empty "<<endl;
	else{
		node *temp=head;
		while(temp->next!=head)
		{
			cout<<temp->data<<"  ";
			temp=temp->next;
		}
		cout<<temp->data<<"  ";
	}cout<<endl;
}
void delete_begin()
{
	if(head==NULL)
	cout<<"EMPTY"<<endl;
	else{
		node *temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		if(temp==head)
		head=NULL;
		else
		{
		temp->next=head->next;
		head=temp->next;
	   }
	}
}
void delete_end()
{
	if(head==NULL)
	cout<<"EMPTY "<<endl;
	else{
		
		node *temp=head,*pr;
		while(temp->next!=head)
		{
			pr=temp;
			temp=temp->next;
		}
		if(temp==head)
		head=NULL;
		else
		pr->next=head;
		delete temp;
	
	}
}
void delete_between()
{
	if(head==NULL)
	cout<<"EMPTY "<<endl;
	else{
		int num;
		cout<<"enter the node u want to delete "<<endl;
		cin>>num;
		
		node *temp=head,*pr;
		while(temp->next!=head && temp->data!=num)
		{
			pr=temp;
			temp=temp->next;
		}
		if(temp->data!=num)
		cout<<"not pos "<<endl;
		else if(temp==head)
		{
			pr->next=head->next;
			head=pr->next;
		}
		else
		{
			pr->next=temp->next;
		}
		delete temp;
	}
}
void rotate()
{
	if(head==NULL)
	cout<<"NO rotation bcz LIST IS EMPTY"<<endl;
	else{
		int num,count=0;
		cout<<"Enter the no. of places that u want to rotate ";
		cin>>num;
		node *temp=head;
		while(temp->next!=head &&count!=num)
		{
			//count++;
		    temp=temp->next;
		    count++;
		}
		head=temp;
	}
}
int main()
{
	while(1){
		int ch;
		cout<<"Enter your choice \n1.CREATE\n2.DISPLAY\n3.DELETE AT BEGIN\n4.DELETE AT END\n5.DELETE AT MID\n6.ROTATE\n"<<endl;
		cin>>ch;
		switch(ch){
			case 1:create();break;
			case 2:display();break;
			case 3:delete_begin();break;
			case 4:delete_end();break;
			case 5:delete_between();break;
			case 6:rotate();break;
			default: display();return 0;
		}
	}
}

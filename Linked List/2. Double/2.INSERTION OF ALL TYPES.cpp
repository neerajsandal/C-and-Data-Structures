#include<iostream>
using namespace std;
struct node{
	int data;
	node *next,*prev;
};
struct node *head=NULL;

void create()
{
	int num;
	cout<<"Enter the no. of elements  ";
	cin>>num;
	while(num!=0){
		node *t=new node;
		cin>>t->data;
		t->next=t->prev=NULL;
		if(head==NULL)
		head=t;
		else{
			node *te=head,*pr;
			while(te->next!=NULL)
			{
				te=te->next;
				pr=te->prev;
			}
			te->next=t;
			t->prev=te;
		}
		num--;
	}
}
void insert_at_begin()
{
	node *temp=new node;
	cin>>temp->data;
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	head=temp;
	else{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void insert_at_end()
{
	node *temp=new node;
	int num;cin>>num;
	temp->data=num;
	temp->next=temp->prev=NULL;
	if(head==NULL)
	head=temp;
	else{
		node *temp1=head;
		while(temp1->next!=NULL)
		temp1=temp1->next;
		
		temp1->next=temp;
		temp->prev=temp1;
	}
}
void display()
{
	if(head==NULL)
    cout<<"LINKED LIST is epmty..."<<endl;
    else
    {
    	node *temp=head;
    	while(temp!=NULL)
    	{
    		cout<<temp->data<<"  ";
    		temp=temp->next;
		}
	}cout<<endl;
}
insert_at_middle()
{
	int a;
	cout<<"Enter the node after which element is to be inserted ";
	cin>>a;
	node *temp=new node;
	cout<<"Enter the element to be inserted ";
	cin>>temp->data;
	temp->next=temp->prev=NULL;
	
	if(head==NULL)
	{
		cout<<"linked list is already empty"<<endl;
	    delete temp;
    }
    else{
    	node *temp1=head;
    	while(temp1!=NULL && temp1->data!=a)
    	temp1=temp1->next;
    	
    	if(temp1==NULL)
    	{
    		cout<<"Element is not found "<<endl;
    	    delete temp;
    	}
    	else if(temp1->next==NULL)
    	{
    		temp1->next=temp;
    		temp->prev=temp1;
		}
		else{
			temp->next=temp1->next;
			temp1->next->prev=temp;
			temp->prev=temp1;
			temp1->next=temp;
		}
	}
}
int main()
{
	do{
		int num;
		cout<<"Enter your choice \n1.CREATE \n2.INSERT AT BEGIN\n3.INSERT AT END\n4.INSERT AT MIDDLE\n5.DISPLAY\n"<<endl;
		cin>>num;
		switch(num){
			case 1:create(); break;
			case 2:insert_at_begin(); break;
			case 3:insert_at_end(); break;
			case 4:insert_at_middle();break;
			case 5:display();break;
			default :return 0;
		}
	}while(1);
	return 0;
}

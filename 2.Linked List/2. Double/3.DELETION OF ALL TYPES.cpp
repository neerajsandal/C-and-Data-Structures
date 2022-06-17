#include<iostream>
using namespace std;
struct node{
	int data;
	node *next,*prev;
};
node *head=NULL;
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
	}
	cout<<endl;
}
void delete_at_begin()
{
	if(head==NULL)
	cout<<"EMPTY "<<endl;
	else{
		node *temp=head;
		head=head->next;
		head->prev=NULL;
		delete temp;
	}
}
void delete_at_end()
{
	if(head==NULL)
	cout<<"EMPTY"<<endl;
	else{
		node *temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		
		if(head==temp)
		head=NULL;
		else
		temp->prev->next=NULL;
		delete temp;	
	}
}
void delete_node()
{
	int num;
	cout<<"Enter the node that u want to delete ";
	cin>>num;
	node *temp=head,*pr;
	while(temp!=NULL && temp->data!=num)
	{
		pr=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	cout<<"NOT FOUND.. "<<endl;
	else if(temp==head)
	{
		head=head->next;
		head->prev=NULL;
	}
	else if(temp->next==NULL)
	{
		temp->prev->next=NULL;
	}
	else{
		pr->next=temp->next;
		temp->next->prev=pr;
	}
	delete temp;
}
void delete_nodeWithPos(){
	int num,count=1;
	cout<<"Enter the position of NODE that u want to delete ";
	cin>>num;
	if(head==NULL)
	cout<<"EMPTY "<<endl;
	else{
		node *temp=head,*pr;
		while(temp!=NULL && count!=num)
		{
			count++;
			pr=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		cout<<"NOT FOUND"<<endl;
		else if(head==temp)
		{
			head=head->next;
			head->prev=NULL;
		}
		else if(temp->next==NULL)
		{
			temp->prev->next=NULL;
		}
		else{
			pr->next=temp->next;
			temp->prev=pr;
		}
		delete temp;
	}
}
int main(){
	do{
		int num;
		cout<<"Enter your choice \n1.CREATE \n2.DELETE AT BEGIN\n3.DELETE AT END\n4.DELETE NODE\n5. DELETE WITH POS\n6.DISPLAY\n"<<endl;
		cin>>num;
		switch(num){
			case 1:create(); break;
			case 2:delete_at_begin(); break;
			case 3:delete_at_end(); break;
			case 4:delete_node();break;
			case 5:delete_nodeWithPos();break;
			case 6:display();break;
			default :display();return 0;
		}
	}while(1);
	return 0;
}

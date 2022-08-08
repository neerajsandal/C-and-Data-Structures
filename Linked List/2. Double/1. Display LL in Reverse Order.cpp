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
	cout<<"Enter the size of linked list ";
	cin>>num;
	while(num!=0){
		node *temp1=new node;
		cin>>temp1->data;
		temp1->next=temp1->prev=NULL;
		if (head==NULL)
		head=temp1;
		else{
			node *temp=head,*prev1;
			while(temp->next!=NULL){
				temp=temp->next;
				prev1=temp->prev;
			}
			temp->next=temp1;
			temp1->prev=temp;
		}
		num--;
	}
}void display()
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
void displayr(){
	if(head==NULL)
	cout<<"linked list is empty "<<endl;
	else{
		node *temp=head;
    	while(temp->next!=NULL)
    	{
    		temp=temp->next;
		}
		head=temp;
		node *prev1=head;
		while(prev1!=NULL)
		{
			cout<<prev1->data<<"  ";
			prev1=prev1->prev;
		}
		cout<<endl;
	}
}
int main()
{
	create();
	display();
	displayr();
}

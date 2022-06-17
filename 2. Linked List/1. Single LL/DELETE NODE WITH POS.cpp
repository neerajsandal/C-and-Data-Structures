#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node *head=NULL;

// TIME COMP. O(N^2)
void Create()
{
		int num;
    cout<<"Enter the size of linked list ";
    cin>>num;
    while(num!=0){
    if(head==NULL)
    {
        head=new node;
        cin>>head->data;
        head->next=NULL;
    }
    else
    {
        node *temp=head,*temp1;
        while(temp->next!=NULL)
        temp=temp->next;
        
        temp1=new node;
        cin>>temp1->data;
        temp1->next=NULL;
        temp->next=temp1;
    }
    num--;
    }
}
// TIME COMP. O(n)
void Create1()
{
	node *tail = NULL;
	char h ='y';
	while(h=='y'){
	node *temp = new node;
	cin>>temp->data;
	temp->next = NULL;
	if(head==NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	cout << "do u want more operation (y/n) ?"<<endl;
	cin>>h;
}
}
void delete_Node_With_Pos()
	{
	    int pos;
	    node *p=head,*q;
	    cout<<"enter the position where you want to delete the element : ";
	    cin>>pos;
	    for(int i=1;i<pos;i++)
	    {
	    	q=p;
	        p=p->next;
	    }
//	    p->next=p->next->next;
        if(p==NULL)
        {
        	cout<<"NOT POSSIBLE "<<endl;
		}
		else
		{
			if(p==head)
			{
				head=head->next;
			}
			else
			{
				q->next=p->next;
				delete p;
			}
		}
	}
	
void Display()
{
	cout<<" ... /// link list ///...."<<endl;
	if(head)
	{
		node *temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
	else
	cout<<"LINKED LIST IS EMPTY ";
	cout<<endl;
}

int main()
{
    
	int a;
	do{
	cout<<"\n Enter your choice \n 1.CREATE.. \n 2.DISPLAY.. \n 3.DELETE.. Node by its Position \n"<<endl;
	cin>>a;
	cout<<endl;
	switch(a)
	{
		case 1: Create1(); break;
		case 2: Display(); break;
		case 3: delete_Node_With_Pos(); break;
		default : cout<<"END...";return 0;
		
	}
	   }while(a);
	   return 0;
}

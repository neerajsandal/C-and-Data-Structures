#include<iostream>
using namespace std;
struct node{
    int data;
    struct node* next;
};
struct node *head=NULL;

void Create()
{
	char ch='y';
    while(ch=='y'){
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
    cout << "do u want more opeartion (y/n) ? " << endl;
	cin>>ch; 
    }
}

void insert_BEGIN()
{
   int n;
   cout<<"Enter the element to be inserted at the head ";
   cin>>n;
   node *temp=new node;
   temp->data=n;
   temp->next=head;
   head=temp;	
}

void insert_END()
{
   int n;
   cout<<"Enter the element to be inserted at the END ";
   cin>>n;
   node *temp1=new node;
   temp1->data=n;
   temp1->next=NULL;
   
   if(head==NULL)
   head=temp1;
   else{
   	node *temp=head;
   	while(temp->next!=NULL)
   	{
   		temp=temp->next;
	   }
	   temp->next=temp1;
   }
}

void insert_MID()
{
	if(head==NULL)
	cout<<"link list is already EMPTY"<<endl;
}

void delete_BEGIN()
{
	if(head==NULL)
	{
		cout<<"Linked List is already EMPTY "<<endl;
	}
	else
	{
		node *temp=head;
		head=head->next;
		delete temp;
	}
}

void delete_END()
{
	if(head==NULL)
	{
		cout<<"Linked List is already EMPTY "<<endl;
     }
    
	else
	{	
	node *temp=head,*pre;
	while(temp->next!=NULL)
	{
		pre=temp;
		temp=temp->next;
	}
	if(temp==head)
	head=NULL;
	else{
	pre->next=NULL;
	delete temp;
    } }
}

void delete_SPECIFIC_NODE()
{
	if(head==NULL)
	cout<<"link list is already EMPTY"<<endl;
}

void Search_Display()
{
	int num;
	cout<<"Enter the element to be Search : ";
	cin>>num;
	if(head==NULL)
	cout<<"link list is already EMPTY"<<endl;
	else
	{
		node* temp=head;
		//while(temp->next!=NULL && temp->data!=num)
		while(temp && temp->data!=num)
		temp=temp->next;
		
		/*if(temp->data==num)
		cout<<"FOUND ..."<<endl;
		else
		cout<<"NOT FOUND ..."<<endl; */
		if(temp==NULL)
		cout<<"noy FOUND ..."<<endl;
		else
		cout<<"FOUND ..."<<endl;
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
	cout<<"\n Enter your choice \n 1.CREATE.. \n 2.INSERT.. AT THE BEGINNING \n 3.INSERT.. AT THE END\n "
	<<"4. INSERT.. THE MID\n 5.DELETE.. AT THE BEGINNING\n 6.DELETE AT THE END\n 7.DELETE.. SPECIFIC NODE\n "<<
	"8.SEARCH.. AND DISPLAY..\n 9.ONLY DISPLAY...\n \n \n CHOICE IS : "<<endl;
	cin>>a;
	cout<<endl;
	switch(a)
	{
		case 1: Create(); break;
		case 2: insert_BEGIN(); break;
		case 3: insert_END(); break;
		case 4: insert_MID(); break;
		case 5: delete_BEGIN(); break;
		case 6: delete_END(); break;
		case 7: delete_SPECIFIC_NODE(); break;
		case 8: Search_Display(); break;
		case 9: Display(); break;
		default : cout<<"END...";return 0;
		
	}
	   }while(a);
	   return 0;
}

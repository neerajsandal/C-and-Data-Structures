#include<iostream>
#include<climits>
using namespace std;
struct node{
	char data;
	node *next;
};
struct node *head = NULL;
void insert_end(char ch)
{
	node *temp1 = new node;
	temp1->data = ch;
	temp1->next = NULL;
	
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
void delete_node(char a)
{
	if(head!=NULL)
	{
		node *temp=head,*pre;
		while(temp->next!=NULL && temp->data!=a)
		{
			pre=temp;
		    temp=temp->next;
	    }
		if(temp==NULL)
		{
		return ; }
		else
		{
			if(head==temp)
			head=head->next;
			else
			{
				pre->next=temp->next;
				delete temp;
			}
		}
	}
}
node *mid(node *head,char data)
{
	node *temp = new node;
	temp->data=data;
	temp->next=NULL;
    if (head == NULL)
    {
        head=temp;
        return head;
    }
    else if(head->next==NULL)
    {
        head->next=temp;
        return temp;
    }
    else
    {
        node* slow = head;
        node* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = slow->next;
        slow->next = temp;
        return head;
    }
}
void check(char ch)
{	
	if(head!=NULL)
	{
		node *temp=head;
		while (temp && temp->data!=ch)
		temp=temp->next;
		
		if(temp==NULL)
		insert_end(ch);
		else
		{
		delete_node(ch);
		head=mid(head,ch);
	    }
    }		
}

int main()
{
	char data[1000]; 
	cin>>data;
	insert_end(data[0]);
	
	for(int i=1;data[i]!='\0';i++)
	{
		check(data[i]);
	}
	node *temp=head;
	int min=INT_MAX;
	int max=INT_MIN;
	node *maxNODE=NULL;
	node *minNODE=NULL;
	node *secondhead;
	while(temp!=NULL)
	{
	    if(temp->data-'a' > max)
	    {
	        max=temp->data-'a';
	        maxNODE=temp;
	    }
	    if(temp->data-'a' < min)
	    {
	        min=temp->data-'a';
	        minNODE=temp;
	    }
	    temp=temp->next;
	}
	    secondhead=minNODE->next;
	    minNODE->next=NULL;
    
    node *temp1=head;
	while(temp1!=NULL)
    {
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
	cout<<"\n";
	
	node *temp2=secondhead;
	while(temp2!=NULL)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
	return 0;
}

#include<iostream>
using namespace std;
struct node{
	int data;
	node *next,*prev;
};
struct node *head=NULL;
node* delete_at_begin()
{
	if(head==NULL)
		return NULL;
	else{
		node *temp=head;
		head=head->next;
		head->prev=NULL;
		delete temp;
	}
	return head;
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
node* delete_at_end()
{
	if(head==NULL)
		return NULL;
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
	return head;
}
int delete_1(node *head, node *tail)
{
	int count = 0, ans = 0;
	while(head->next!=NULL)
	{
		if(head->data <= tail->data)
	   	{
	   		 ans = head->data;
	   		head = delete_at_begin();
	   	//	cout << ans << " " << head->data << endl;
	   		if(ans <= head->data )
	   			count++;
		   }
	   	else
	   	{
	   		 ans = tail->data;
	   		tail = delete_at_end();
	   	//	cout << ans << " " << tail->data << endl;
	   		if(ans <= head->data)
	   			count++;
		   }
	}
	if(ans <= head->data)
	count++;
	return count;
}
int create()
{
	int num;
	cin>>num;
	node *tail;
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
		tail = t;
	}
	int c = delete_1(head,tail);
	return c;
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
int main()
{
	int n;
    cin >> n;
    
    int n1 = n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    	arr[i] = 0;
    int i = 0;
    while(n!=0)
	{
		int c = create();
		arr[i] = c;
		i++;
		n--;
	}
	
	for(int i = 0; i < n1; i++)
    {
    	cout << "Case #" << i+1 <<": "<<arr[i] << endl;
	}
}

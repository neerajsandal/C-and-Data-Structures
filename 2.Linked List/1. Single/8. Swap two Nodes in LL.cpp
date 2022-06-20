#include <iostream>
#include<cmath>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
Node *swapNodes(Node *head, int i, int j)
{
    
    if(head==NULL || head->next==NULL || i==j)
        return head;
    
    Node *current1=NULL,*prev1=NULL,*current2=NULL,*prev2=NULL;
     int i1= i;
     int i2=j;
     i=min(i1,i2);
     j=max(i1,i2);
    Node *temp=head,*prev=NULL;
    int count=0;
    while(temp)
    {
     
        if(count==i)
        {
            current1=temp;
            prev1=prev;       
        }
        
        else if(count==j)
        {
            current2=temp;
            prev2=prev;
           
        }   
        prev=temp;
        temp=temp->next;
        count++;
    }

    if(prev1==NULL)
    {
        {
         Node *temp2=current2->next;
    current2->next=current1->next;
    current1->next=temp2;
        prev2->next=current1;
          head=current2;
    }}
    else if(prev1!=NULL && prev2!=NULL)
    {
        
        if(abs(i-j)==1)
        {
            Node *forward1=current2->next;
            current2->next=current1;
            current1->next=forward1;
            prev1->next=current2;
        }
        else
        {
        Node *temp2=current2->next;
    current2->next=current1->next;
     current1->next=temp2;
            prev1->next=current2;
            prev2->next=current1;         
        }
    }
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cout << "Enter the No. cases : " << endl;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cout << "Enter the elements that u want to swap : " << endl;
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}

/*

Sample Input :
Enter the No. cases :
2
10 20 30 40 -1
Enter the elements that u want to swap :
1
2
70 80 90 25 65 85 90 -1
Enter the elements that u want to swap :
0 6


Output:
10 30 20 40 
90 80 90 25 65 85 70 
*/

/*....

You have been given a singly linked list of integers along with an integer 'N'. 
Write a function to append the last 'N' nodes towards the front of the singly linked list
and returns the new head to the list.

..*/


#include <iostream>
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
int length(Node *head)
{
    if(head==NULL)
        return 0;
    return 1+length(head->next);
}
Node *appendLastNToFirst(Node *head, int n)
{
    int c = length(head);
    if(head == NULL)
        return head;
    if(n==0)
        return head;
    if(n<c)
    {
        int x = 1;
        Node *tail = head;
        Node *oldhead = head;
        while(x<c-n)
        {
            tail = tail->next;
            x++;
        }
        head = tail->next;
        tail->next = NULL;
        
        Node *temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = oldhead;
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
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int n;
		cout << "Enter the postion of Node FROM END: that u want to insert at first" << endl;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}

/*
Sample Input:
1
10 6 77 90 61 67 100 -1
Enter the postion of Node FROM END: that u want to insert at first
4

Sample Output:
90 61 67 100 10 6 77



Explainations:
We have been required to move the last 4 nodes to the front of the list. Here, "90->61->67->100" is the list which represents the last 4 nodes.
When we move this list to the front then the remaining part of the initial list which is,
"10->6->77" is attached after 100. Hence, the new list formed with an updated head pointing to 90.
*/

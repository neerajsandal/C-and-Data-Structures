/* ... 

kReverse

Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time 
and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, 
should be reversed as well.

Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4

*/

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
Node *kReverse(Node *head, int k)
{
    Node *curr = head;
    Node *prev = NULL, *next =  NULL;
        if(curr==NULL || k==0)
        {
            return head;
        }
        int m = 0;
        while(curr!=NULL && m!=k)
        {
            m++;
            next = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = next;
        }
    Node *tt = prev;
    Node *temp = kReverse(curr,k);
    head->next = temp;
    return tt;
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
	cout << "Enter the cases : ";
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int k;
		cout << "Enter the Position : ";
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}

/*
Sample Input :

Enter the cases : 1
1 2 3 4 5 6 7 8 9 10 -1
Enter the Position : 4

Sample Output
4 3 2 1 8 7 6 5 10 9
*/

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

Node *removeDuplicates(Node *head)
{
    if(head==NULL)
        return head;
    Node *temp = head->next,*prev = head;
    while(temp!=NULL)
    {    
        if(temp->data == prev->data)
        {
            temp = temp->next;
            prev->next=temp;
        }
        else
        {
             prev = temp;
             temp = temp->next;
        }
    }delete temp;
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
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}

/*
Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1

Sample Output 1 :
1 2 3 4 5 7 


Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1

Sample Output 2 :
10 20 30 40 50
10
*/

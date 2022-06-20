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

void printReverse(Node *head)
{
    if(head==NULL)
        return;
    else if (head->next == NULL)
    {
        cout << head->data;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;   
    while(curr!=NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
        head = prev;
        Node *temp = head;
       while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
     }
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}

/*
Sample Input 1 :
1
1 2 3 4 5 -1

Sample Output 1 :
5 4 3 2 1


Sample Input 2 :
2
1 2 3 -1
10 20 30 40 50 -1

Sample Output 2 :
3 2 1
50 40 30 20 10
*/

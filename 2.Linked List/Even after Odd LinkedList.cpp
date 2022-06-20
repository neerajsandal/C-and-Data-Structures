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
Node *evenAfterOdd(Node *head)
{
   if(head==NULL || head->next==NULL)
       return head;
    else{
        Node *evenhead = NULL ,*oddhead = NULL ,*eventail = NULL, *oddtail = NULL;
        Node *temp =head;
        while(temp!= NULL)
        {
            if(temp->data %2==0)
            {
                if(evenhead==NULL)
                {
                    evenhead = temp;
                    temp = temp->next;
                    evenhead->next = NULL;
                    eventail =  evenhead;
                }
                else{
                    eventail->next = temp;
                    eventail = temp;
                    temp = temp->next;
                    eventail->next = NULL;
                }
            }
            else{
                if(temp->data %2!=0)
            {
                if(oddhead==NULL)
                {
                    oddhead = temp;
                    temp = temp->next;
                    oddhead->next = NULL;
                    oddtail = oddhead;
                }
                else{
                    oddtail->next = temp;
                    oddtail = temp;
                    temp = temp->next;
                    oddtail->next = NULL;
                }
            }
        }
    }
        if(oddhead==NULL)
            return evenhead;
        else 
        {
        oddtail->next = evenhead;
        return oddhead;
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
	cout << "Enter the Number of Cases: "<< end;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}

/*
Sample Input 1 :

Enter the Number of Cases: 
1
1 4 5 2 -1

Sample Output 1 :
1 5 4 2 




Sample Input 2 :

Enter the Number of Cases: 
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1

Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40

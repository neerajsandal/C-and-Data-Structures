//bubble sort iterative
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

int len(Node* head)
{
    Node* temp = head ;
    int i = 0 ;
     while(temp!=NULL)
     {
         i++;
         temp=temp->next ;
     }
    
    return i ;
}
Node *bubbleSort(Node *head)
{
         if(head==NULL || head->next==NULL)
         {
             return head;
         }
         int ln = len(head);
         for(int i = 1;i<ln;i++){
             Node *curr = head,*prev=NULL;
             while(curr->next!=NULL){
        if(curr->data > curr->next->data)
        {
            if(prev == NULL)
            {
                Node *nxt = curr->next;
                curr->next = nxt->next;
                nxt->next = curr;
                prev = nxt;
                head = prev;
            }
            else{
                Node *nxt = curr->next;
                prev->next = nxt;
                curr->next = nxt->next;
                nxt->next = curr;
                prev = nxt;
            }
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }   
   }
    return head ;
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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}

/*

Sample Input 1 :
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
3 4 5 6 7 8 9 10 
 
 
 
Sample Input 2 :
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :
-5 1 5 9 10 67 89 90 

*/

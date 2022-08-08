#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
node *head = NULL;
void create()
{
	cout<<"Enter the size of linked list : "<<endl;
	int num;
	cin >> num;
	while(num!=0)
	{
	node *temp  = new node;
	cin >> temp->data;
	temp->next = NULL;
	
	if(head == NULL)
	head = temp;
	else{
		node *temp1 = head;
		while(temp1->next != NULL)
		temp1 = temp1->next;
		
		temp1->next = temp;
	}
	num-- ;
    }
}
void middle()
{
	node *single_move = head;
	node *double_move = head;
	while(double_move != NULL  /*for odd*/  || double_move->next != NULL  /*for even*/)
	{
		single_move = single_move->next; 
		double_move = double_move->next->next;
	}
	cout << "Middle_element : " << single_move->data << endl;
}
void print()
{
	node *temp = head;
	while(temp)
	{
		cout << temp->data << "  ";
		temp = temp->next; 
	}
}
int main()
{
    create();
	print();
	middle();	
}

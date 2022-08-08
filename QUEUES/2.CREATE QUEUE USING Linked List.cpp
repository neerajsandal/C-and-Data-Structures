#include<iostream>
using namespace std;
class Node{
	public:
	   int data;
	   Node *next;
	   Node(int data)
	   {
	   	  this->data = data;
	   	  next = NULL;
	   }
};
class queue{
	int size;
	Node *front;
	Node *rear;
	public:
		void init()
		{
			front = NULL;
			rear = NULL;
			size = 0;
		}
		bool isEmpty()
		{
		    return front == NULL;
		}
		bool isFull()
		{
			Node *temp = new Node(0);
			if(temp==NULL)
			return true;
			else
			return false;
		}
		int Size()
		{
			if(isEmpty())
			return -1;
			else
			return size;
		}
		// if we dont maintain the size the we have to iterate the linked to find the size;
		int peek()
		{
			if(!isEmpty())
			return front->data;
			else
			return -1;
		}
		void enqueue(int element)
		{
			Node *temp = new Node(element);
			
			if(isEmpty())
			{
				front = temp;
				rear = temp;
			}
			else{
				rear->next = temp;
				rear = temp;
			}
			size++;
		}
		void dequeue()
		{
			if(!isEmpty())
			{
				Node *temp = front;
				if(front == rear)
				{
					front = NULL;
					rear = NULL;
				}
				else{
				    front = front->next;
				}
				cout << "dequeue : " << temp->data << endl;
				size--;
				delete temp;
			}
			else
			{
				cout << "Underflow " << endl;
			}
		}
		void print()
		{
			Node *temp = front;
			while(temp!=NULL)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout << endl;
		}
};
int main()
{
	queue q;
	q.init();
	cout << "isEmpty : " << q.isEmpty() << endl;
	q.enqueue(16);
	q.enqueue(24);
	q.enqueue(18);
	q.enqueue(27);
	q.enqueue(29);
	q.print();
	cout << "isFull : " << q.isFull() << endl;
    q.dequeue();
	q.dequeue();
	cout << "peek of the queue : " << q.peek() << endl;
	cout << "size : " << q.Size() << endl;
	q.enqueue(30);
	cout << "isFull : " << q.isFull() << endl;
	cout << "isEmpty : " << q.isEmpty() << endl;
    q.dequeue();
    q.dequeue();
	cout << "peek of the queue : " << q.peek() << endl;
	 
	 return  0;
}

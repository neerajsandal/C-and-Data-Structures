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
			size = 0;
			front = NULL;
			rear = NULL;
		}
		bool isEmpty()
		{
			return front == NULL;
		}
		bool isFull()
		{
			Node *temp = new Node(0);
			if(temp == NULL)
			return true;
			else
			return false;
		}
		int Size()
		{
			return size;
		}
		void enqueue(int element)
		{
			Node *temp = new Node(element);
			if(isEmpty())
			{
				front = temp;
				rear = temp;
				rear->next = front;
			}
			else{
				rear->next = temp;
				rear = temp;
				rear->next = front;
			}
			size++;
		}
		int peek()
		{
			if(front!=NULL)
			return front->data;
		}
		int dequeue()
		{
		    if(isEmpty())
			return -1;
			else{
				int top = front->data;
				Node *temp = front;
				front = front->next;
				rear->next = front;
				size--;
				delete temp;
				return top;
			}	
		}
		void print()
		{
			Node *temp = front;
			while(temp->next!=front)
			{
				cout << temp->data << "  ";
				temp = temp->next;
			}
			cout << temp->data << endl;
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
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "peek of the queue : " << q.peek() << endl;
	cout << "size : " << q.Size() << endl;
	q.enqueue(30);
	cout << "isFull : " << q.isFull() << endl;
	cout << "isEmpty : " << q.isEmpty() << endl;
	cout << "dequeue : " << q.dequeue() << endl;
	q.print();
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "peek of the queue : " << q.peek() << endl;
    return  0;
}

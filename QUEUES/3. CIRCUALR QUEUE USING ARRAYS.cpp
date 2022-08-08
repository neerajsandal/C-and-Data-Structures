#include<iostream>
using namespace std;
class queue{
	int size;
	int *arr;
	int front;
	int rear;
	public:
		void init(int size)
		{
			this->size = size;
			arr = new int[size];
			front = -1;
			rear = -1;
		}
		bool isEmpty()
		{
			return front==-1;
		}
		bool isFull()
		{
			return (front == (rear+1)%size);
		}
		int Size()
		{
			if(front <= rear)
			return (rear - front + 1);
			else
			return (size-(front-rear-1));
		}
		int peek()
		{
			if(!isEmpty())
			return arr[front];
		}
		void enqueue(int element)
		{
			if(isFull())
			cout << "Overflow " << endl;
			else{
				rear = (rear + 1) % size;
				arr[rear] = element;
				if(front == -1)
				{
					front = 0;
				}
			}
		}
		void pos_front_top()
		{
			cout << "front : " << front << endl;
			cout << "rear : " << rear << endl;
		}
		int dequeue()
		{
			if(isEmpty())
			cout << "Underflow" <<endl;
			else {
				int top = arr[front];
			    if(front == rear)
			    {
				   front = -1;
				   rear = -1;
			    }
			    else
			    front = (front + 1) % size;
			    return top;
		    }
		}
		void print()
		{
			if(!isEmpty())
			{
				if(front <= rear)
			    {
			    	for(int i = front; i <= rear; i++)
			    	cout << arr[i] << "  ";
			    	cout << endl;
				}
				else{
					for(int i = front; i < size; i++)
					cout << arr[i] << "  ";
					for(int i = 0; i <= rear; i++)
					{
					cout << arr[i] << "  ";
				   }
				}
				cout << endl;
			}
			else{
				cout << "Queue is EMPTY" << endl;
			}
		}
};
int main()
{
	queue q;
	q.init(5);
	cout << "isEmpty : " << q.isEmpty() << endl;
	q.enqueue(16);
	q.enqueue(24);
	q.enqueue(18);
	q.enqueue(27);
	q.enqueue(29);
	q.print();
	cout << "isFull : " << q.isFull() << endl;
	q.pos_front_top();	
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "dequeue : " << q.dequeue() << endl;
	q.pos_front_top();
	cout << "peek of the queue : " << q.peek() << endl;
	cout << "size : " << q.Size() << endl;
	q.enqueue(30);
	cout << "isFull : " << q.isFull() << endl;
	cout << "isEmpty : " << q.isEmpty() << endl;
	cout << "dequeue : " << q.dequeue() << endl;
	q.pos_front_top();
	q.print();
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "peek of the queue : " << q.peek() << endl;
    return  0;
}

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
			return front==-1 || front>rear;
		}
		bool isFull()
		{
			return rear==size-1;
		}
		void pos_front_top()
		{
			cout << "front : " << front << endl;
			cout << "rear : " << rear << endl;
		}
		int Size()
		{
			if(!isEmpty())
			return (rear - front + 1);
			else
			return -1;
		}
		void enqueue(int element)
		{
			if(isFull())
			cout << "Overflow " << endl;
			else if(front==-1)
			{
				front++;
				rear++;
				arr[rear] = element;
			}
			else{
				rear = rear+1;
				arr[rear] = element;
			}
		}
		int peek() //void front()
		{
			if(isEmpty())
			return -1;
			else
			return arr[front];
		}
		int dequeue()
		{
			if(isEmpty())
			return -1;
			else if(front == rear)
			{
				int top = arr[rear];
				front--;
				rear--;
				return top;
			}
			else{
				int pop = arr[front];
				front++;
				return pop;
			}
		}
		void print()
		{
			if(!isEmpty())
			{
			   for(int i = front; i <= rear; i++)
			        cout << arr[i] << "  ";
			    cout << endl;
			}
			else
			cout << "QUEUE is Empty" << endl;
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
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "peek of the queue : " << q.peek() << endl;
	cout << "size : " << q.Size() << endl;
	q.enqueue(30);
	cout << "isFull : " << q.isFull() << endl;
	cout << "isEmpty : " << q.isEmpty() << endl;
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "dequeue : " << q.dequeue() << endl;
	cout << "peek of the queue : " << q.peek() << endl;
	 
	 return  0;
}

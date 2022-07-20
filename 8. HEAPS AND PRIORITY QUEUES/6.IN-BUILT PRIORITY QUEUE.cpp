// In-Built Priority Queue is by-default Max Priority Queue 
#include<iostream>
using namespace std;
#include<queue>
int main()
{
	priority_queue<int> pq;  //Max Priority Queue 
	
	pq.push(16);
	pq.push(1);
	pq.push(167);
	pq.push(45);
	
	cout << "SIZE : " << pq.size() << endl;
	cout << "TOPMOST : " << pq.top() << endl;
	
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

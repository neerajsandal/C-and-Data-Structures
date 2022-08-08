#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int, vector<int>, greater<int> > pq;  // Min Priority Queue
	pq.push(53);
	pq.push(89);
	pq.push(17);
	pq.push(108);
	
	cout << "SIZE : " << pq.size() << endl;
	cout << "TOPMOST : " << pq.top() << endl;
	
	while(!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl; 
}

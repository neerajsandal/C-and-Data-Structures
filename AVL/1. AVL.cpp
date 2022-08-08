#include<iostream>
using namespace std;
int avl(int h)
{
	if(h == 0)
	{
		return 0;
	}
	if(h == 1)
	return 1;
	return 1 + avl(h-1) + avl(h-2);
}
int main()
{
	int h;
	cout << "Enter the height : "<< endl;
	cin >> h;
	int c = avl(h);
	cout << "No. of nodes : " << c << endl;
}

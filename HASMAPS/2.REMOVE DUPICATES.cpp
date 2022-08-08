#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> removeDuplicates(int *arr, int size)
{
	unordered_map<int,bool> ourmap;  // stores "true" value for the given key if it is present
	vector<int> v;
	for(int i = 0; i < size; i++)
	{
		if(ourmap.count(arr[i]) > 0)
		    continue;   //  continue the for loop it the key is alaedy present
		 else
		{
		    ourmap[arr[i]] = true;
		    v.push_back(arr[i]);
		}
	}
	return v;
}
int main()
{
	int arr[] = {1,2,4,2,1,6,8,3,1,2,36,2,1,4,6,7,9,4,3,5,5,3,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << size << endl;
	vector<int> v = removeDuplicates(arr,size);
	for(int i = 0; i < v.size(); i++)
	   cout << v[i] << " ";
	cout << endl;
}

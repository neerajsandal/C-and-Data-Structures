#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    
    vector<int> :: iterator it = v.begin();
    while(it != v.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    v.erase(v.begin(),v.begin()+3);  // delete 1 2 3
    //erase() works best with elements in a position, 
	//remove() is best while working with range of elements.	
	//vector<int>::iterator new_end = remove(v.begin(), v.end(), 20);
	
    vector<int> :: iterator it2 = v.begin();
    while(it2 != v.end())
    {
        cout << *it2 << " ";
        it2++;
    }
}
    

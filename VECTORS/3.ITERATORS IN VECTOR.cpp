#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    //Insert values 1 to 10
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(20);
    v.push_back(10);

    vector<int>::iterator new_end;
    new_end = remove(v.begin(), v.end(), 20);
    //erase() works best with elements in a position, 
	//remove() is best while working with range of elements.
    // Remove all 20's from begin to last

    vector<int> :: iterator it2 = v.begin();
    while(it2 != v.end())
    {
        cout << *it2 << " ";
        it2++;
    }
    return 0;
}

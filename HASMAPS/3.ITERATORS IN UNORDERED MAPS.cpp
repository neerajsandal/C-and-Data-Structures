#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc"] = 0;
    ourmap["abc1"] = 1;
    ourmap["abc2"] = 2;
    ourmap["abc3"] = 3;
    ourmap["abc4"] = 4;
    
    // how to print the "key" and the corresponding "values" in the unordered_map
    // It is only possible with the help of iterators
    // Iterator in unordered_map print the "keys" and "values" in any order 
    // But in case of map (ordered_map), "keys" and "values" are print in an ordered way
    unordered_map<string,int> :: iterator it = ourmap.begin(); 
    // initialise the iterator with the starting address of unordered_map
    
    while(it != ourmap.end())
    {
        cout << "key : " << it->first << " " << it->second << endl;
        it++;
    }
    
    // It is also used to find some element/key 
    unordered_map<string,int> :: iterator it1 = ourmap.find("abc3");
    // Also used to delete some key/value
    ourmap.erase(it1); // delete key "abc3";
    
    cout << "unordered_map after one deletion  " << endl;
    unordered_map<string,int> :: iterator it2 = ourmap.begin(); 
    while(it2 != ourmap.end())
    {
        cout << "key : " << it2->first << " " << it2->second << endl;
        it2++;
    }
}
    

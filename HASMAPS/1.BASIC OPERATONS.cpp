#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
	unordered_map<string,int> ourmap;  // Initialse the unoredred map
	pair<string,int> p("abc",7);  
	ourmap.insert(p);    // Way 1 of insertion 
	
	ourmap["def"] = 9; // way 2 of insertion
	
	cout << ourmap["abc"] << endl;
	cout << ourmap.at("def")<< endl;
	
	cout << "size : " << ourmap.size() << endl;
	
	cout << ourmap.at("hht") << endl; // it will generate an aerror if the key is not present
	cout << ourmap["hht"] << endl; 
	// since it is not present,it will print 0 and insert a value to given key
	
	cout << "size : " << ourmap.size() << endl;
	
	if(ourmap.count("hht") > 0)   //  print present, since it was inserted by --> cout << ourmap["hht"]  
		cout << "Present" << endl;
	else
	    cout << "Not Present" << endl;
	    
	ourmap.erase("hht");
	cout << "size : " << ourmap.size() << endl;
}

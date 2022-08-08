#include<iostream>
#include<string>
using namespace std;

template<typename V>

// class for creating a Node for chaining;
class MapNode{
	
	public : 
	string key;   // we have taken key in the form of string
	V value;   // Value is taken as template
	MapNode *next;
	
	MapNode(string key, V value)
	{
		this->key = key;
		this->value = value;
		next = NULL;
	} 
	
	~MapNode()
	{
		delete next;
	}
};

// Actual HashMap Class
template<class V>
class OurMap{
	MapNode<V> **Bucket_Array;   // Array that stores the address of Node so we used **
	int No_Buckets;   // Size of an Array
	int count;  // that tells the total no. of nodes (or size) in our HashMaps
    
    public:
    	OurMap()
    	{
    		count = 0;  //  Initialse the size to 0;
    		No_Buckets = 5;
    		Bucket_Array = new MapNode<V>*[No_Buckets];
    		
    		// Initialise all the Index of Bucket_array that stores the addresses as NULL 
    		for(int i = 0; i < No_Buckets; i++)
    		{
    			Bucket_Array[i] = NULL;
			}
		}
		
		~OurMap()
		{
			// to delete our HashMap, 
			// First of all delete all the Nodes correspondes to each Bucket of an array;
			// Then delete the array
			
			for(int  i = 0; i < No_Buckets; i++)
			{
				delete Bucket_Array[i];  // delete all Nodes at 'i'th index
			}
			delete [] Bucket_Array;
		}
		
		private:
			int getIndex(string key)
			{
				int HashCode = 0;
				int coeff = 1;
				
				for(int i = key.size() - 1; i >= 0 ; i--)
				{
					HashCode += key[i] * coeff;  // Method 3 is used for getting string to integer HashCode
					HashCode %= No_Buckets; 
					// reduces the HashCode so that it doesn't get out of the rage of integers
					
					coeff *= 37;
					coeff %= No_Buckets;
					//reduces the Coeff so that it doesn't get out of the rage of integers
				}
				return HashCode % No_Buckets;
			}
		public:
		int size()
		{
			return count;
		}
		
		void Insert(string key, V value)
		{
			int index = getIndex(key);
			MapNode<V> *head = Bucket_Array[index];
			
			// to check whether the key is aleady present for that given index or not
			while(head != NULL)
			{
				if(head->key == key)
				   return;
				head = head->next;
			}
			
			head = Bucket_Array[index];  // head points to starting index of an array
			MapNode<V> *node = new MapNode<V>(key,value);
			node->next = head; 
			
			Bucket_Array[index] = node; // now index will points to the Node;
			count++;
		}
		
		V Delete(string key)
		{
			int index = getIndex(key);
			MapNode<V> *head = Bucket_Array[index];
		    MapNode<V> *prev = NULL;
		    
		    while (head != NULL)
		    {
		    	if(head->key == key)
		    	{
		    		if(prev == NULL)
		    		{
		    			Bucket_Array[index] = head->next;
					}
					else{
						prev->next = head->next;
					}
					
					V value = head->value;
					head->next = NULL; 
					// it will delete only desired Node bcz next is NULL now.  otherwise,
					//all the nodes of that index got deleted bcz deletion is recursive in Destructor 
					count--;
					delete head;
					
					return value;
				}
				else{
					prev = head;
					head = head->next;
				}
			}
			return 0;
		}
		
		V Search(string key)
		{
		    int index = getIndex(key);
			MapNode<V> *head = Bucket_Array[index];
			
			while(head != NULL)
			{
			    if(head->key == key)
				{
					return head->value;
				}
				head = head->next;	
			}
			return 0;	
		}
		void print()
		{
			for(int i = 0; i < No_Buckets; i++)
			{
				cout << i;
				MapNode<V> * head = Bucket_Array[i];
				while(head != NULL) 
				{
					cout << "-->" << head->key;
					head = head->next;
				}
				cout << endl;
			}
		}
};
int main()
{
	OurMap<int> map;
	cout << "Enter the operations that u want to want to perform In HashMaps" << endl;
	cout << "\n 1. INSERT a Key \n 2. DELETE a Key\n 3. SEARCH a Key \n 4. SIZE \n 5. PRINT\n 6. ANY Value -> Stop \n " << endl;
	
	cout << "Enter your choice : ";
	int choice ;  cin >> choice;
	
	while(1){
	switch(choice)
	{
		case 1: {
			cout << endl;
			string s; 
			cout << "Enter the key as string u want to insert: " << endl;
			cin >> s;
			
			int value; 
			cout << "Enter the value corresponds to a key : " << endl;
			cin >> value;  
			
			map.Insert(s,value);
			cout << endl;
			break;
		}
		case 2: {
			cout << endl;
			string s; 
			cout << "Enter the key as string u want to delete: " << endl;
			cin >> s;
			
			int v = map.Delete(s);
			
			if(v != 0)
				cout << "key got deleted having value : " << v << endl;
			else
			    cout << "Key is not present " << endl;
			    cout << endl;
			break;
		}
		case 3: {
			cout << endl;
			string s; 
			cout << "Enter the key as string u want to search: " << endl;
			cin >> s;
			
			int v = map.Search(s);
			
			if(v != 0)
				cout << "key Found having value : " << v << endl;
			else
			    cout << "Key NOT FOUND !! " << endl;
			    cout << endl;
			break;			
		}
		case 4:{
			cout << endl;
			cout << "Size of HashMap is : " << map.size() << endl;
			cout << endl;
			break;
		}
		case 5:{
			cout << endl;
			map.print();
			cout << endl;
			break;
		}
		default:{
			return 0;
			break;
		}
	}
	cout << "U want more operations :(y/n) ";
	char ch;
	if(ch == 'n')
	  return 0;
	cout << "\n 1. INSERT a Key \n 2. DELETE a Key\n 3. SEARCH a Key \n 4. SIZE\n 5. PRINT \n 6. ANY Value -> Stop \n " << endl;
	
	cout << "Enter your choice : ";
    cin >> choice;
	}  
}
// 1 abc 0 1 abc1 1 1 abc2 2 1 abc3 3 1 abc4 4 

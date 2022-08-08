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
		
		void rehash()
		{
			MapNode<V> **temp = Bucket_Array;  
			// Create a temporary Array which will points to previous array 
			int oldBucket = No_Buckets;
			No_Buckets *= 2;
			Bucket_Array = new MapNode<V> *[No_Buckets];
			
			// Initialse all indexes of an Array as ---> NULL
			for(int i = 0; i < No_Buckets; i++)
			{
				Bucket_Array[i] = NULL;
			}
			
			// Rehashing Begins;
			count  = 0;
			for(int i = 0; i < oldBucket; i++)
			{
				MapNode<V> *head = temp[i];
				while(head != NULL)
				{
					string key = head->key;
					V value = head->value;
					Insert(key,value);
					head = head->next;
				}
			}
			
			// deletion of temporary array
			for(int i = 0; i < oldBucket; i++)
			{
				MapNode<V>* head = temp[i];
				delete head;    //  delete all the nodes corresponds to that index
			}
			delete [] temp;  // then delete the array
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
			
			double LoadFactor = getLoadFactor();
			if(LoadFactor > 0.7)
			{
				rehash();
			}
		}
		
		double getLoadFactor()
		{
			return (1.0 *count)/No_Buckets;
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
   // since initial size of an array is 5  i.e. we need to rehash an array when 4 elements got inserted 
   // bcz load factor > 0.7   i.e. load Factor = 0.8 at this case
   // so, for 10, no. of elements, we have to rehash the array twice;
   for(int i = 0; i < 10; i++)
   {
   	   char ch = '0' + i;
   	   string key = "abc";
   	   key = key + ch;
   	   int value = i + 1;
   	   map.Insert(key,value);
   	   cout << "Load Factor : " << map.getLoadFactor() << endl;
    }
    cout << "\n Size of Map : " << map.size() << endl;
    map.Delete("abc2");
    map.Delete("abc6");
    
    cout << "Size of Map : " << map.size() << endl <<  endl;
	   
    for(int i = 0; i < 10; i++)
    {
   	   char ch = '0' + i;
   	   string key = "abc";
   	   key += ch;
   	   cout << key << " : " << map.Search(key) << endl; 
    } 
	 // Note : delete key print '0' values 
}
// 1 abc 0 1 abc1 1 1 abc2 2 1 abc3 3 1 abc4 4 

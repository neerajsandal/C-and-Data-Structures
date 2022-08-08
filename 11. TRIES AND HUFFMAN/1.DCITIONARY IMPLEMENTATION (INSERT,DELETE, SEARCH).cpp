// For Dictionary Implementation
#include<iostream>
#include<string>
using namespace std;
class TrieNode{
	
	public:
	char data;  // A Node stores a single char of a word;
	TrieNode ** children;  // Dynamic Children array that stores the address of each TrieNode;
	bool isTerminal; // to check whether the given node is terminal node of each word or not;
	
	TrieNode(char data)
	{
		this->data = data;
		children = new TrieNode*[26];   // TrieNode* is used bcz it is storing the address of Node;
		for(int i = 0; i < 26; i++)
		{
			children[i] = NULL;    // initialse all the address it to NULL
		}
		isTerminal = false;
	}
};

class Trie{
	TrieNode *root;
	
	public:
		Trie(){
			root = new TrieNode('\0');  // initialse 'root' Node with data '\0' or NULL; 
		}
		
		void insertWord(TrieNode *root, string word)
		{
			// Base Case
			if(word.size() == 0)
			{
				root->isTerminal = true; // make isTerminal 'True' for last char
				return;
			}
			
			// small calc
			int index = word[0] - 'a';
            // chars are stored as a -> 1 , b -> 2, c -> 3,   and  so on in array
			TrieNode *temp;
			if(root->children[index] != NULL){
			    temp = root->children[index];
				//temp Node stores the address of children Node of root;
			}
			else{
				temp = new TrieNode(word[0]);  // a Node is created with data = word[0];
				root->children[index] = temp;  
				// address of child Node is stored in root->chidren[index] 
			}
			
			// recursive call
			insertWord(temp,word.substr(1)); 
			// passing the childNode with substring starting from 1st position
		}
		void insertWord(string word)
		{
			insertWord(root,word);
		}
	
		bool searchWord(TrieNode *root, string word)
		{
			if(word.size() == 0)
			{
				if(root->isTerminal == true)
				   return true;
				else
				   return false;
			}
			
			int index = word[0] - 'a';
			TrieNode *temp = root->children[index];
			if(temp != NULL)
			{
				return searchWord(temp,word.substr(1));
			}
			return false;
		}
		bool searchWord(string word){
			return searchWord(root,word);
		}
		void removeWord(TrieNode *root, string word)
		{
			if(word.size() == 0)
			{
				root->isTerminal = false;  // make the last char's terminal as false 
				return;
			}
			
			int index = word[0] - 'a';
			TrieNode *child;
			if(root->children[index] != NULL){
				child = root->children[index];
			}
			else{
				// word not found
				
				return;
			}
			
			removeWord(child,word.substr(1));
			
			if(child->isTerminal == false)
			{
				for(int i = 0; i < 26; i++)
				{
					if(child->children[i] != NULL)
						return;   //  if child have further child then simply return
				}
				delete child;  //  if child doesn't have any further child then delete pointer first
				root->children[index] = NULL; // now make it address as NULL to delete that child
			}
		}
		void removeWord(string word){
			removeWord(root,word);
		}
};

int main()
{
   Trie t;
   cout << "Dictionary Implementation !! " << endl;
   cout << "\n 1. Insert a word \n 2. Delete a word \n 3. Search a word" << endl;
   cout << "\n Enter your choice " << endl;
   int choice;
   cin >> choice;
   
   while(1){
      switch(choice){
      	case 1:{
      		cout << "\n Enter the word u want to insert : ";
      		string word;
      		cin >> word;
      		t.insertWord(word);
			break;
		  }
		case 2:{
      		cout << "\n Enter the word u want to search : ";
      		string word;
      		cin >> word;
      		cout << (t.searchWord(word) ? "Found !! " : "Not Found !!") << endl;
			break;
		  }
		case 3:{
			cout << "\n Enter the word u want to delete : ";
      		string word;
      		cin >> word;
      		t.removeWord(word);
			break;
		}
		default:{
			return 0;
			break;
		}
	  }
	  cout << "\n Enter your choice " << endl;
	  cin >> choice;	
   }	
}

#include<iostream>
using namespace std;
class BST{
	public:
		int data;
		BST *left;
	    BST *right;
};
BST *getnewNode(int data)
{
	BST *Node = new BST();
	Node->left = Node->right = NULL;
	Node->data = data;
}
BST *insert(BST *root, int data) // recursively
{
	if(root==NULL)
	{
		root = getnewNode(data);
	}
	else if(root->data >= data)
	{
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
}
//BST *insert(BST *root, int data)
//{
//	BST *Node = getnewNode(data);
//	if(root==NULL)
//	{
//		return Node;
//	}
//	BST *Parent = NULL, *Current = root;
//	while(Current!=NULL)
//	{
//		Parent = Current;
//		if(Current->data >= data){
//			Current = Current->left;
//		}
//		else{
//			Current = Current->right;
//		}
//	}
//	if(Parent->data >= data){
//		Parent->left = Node;
//	}
//	else{
//		Parent->right = Node;
//	}
//	return root;
//}
void Inorder(BST *root)
{
	cout << "inorder" << endl;
	if(root!=NULL)
	{
		Inorder(root->left);
		cout << root->data << "  ";
		Inorder(root->right);
	}
}
void preorder(BST *root)
{
	cout << "preorder" << endl;
	if(root!=NULL)
	{
		cout << root->data << "  ";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(BST *root)
{
	cout << "postorder" << endl;
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << "  ";
	}
}
void search(BST *root,int data)
{
	while(root!=NULL && root->data!=data)
	{
		if(root->data >= data)
		root = root->left;
		else
		root = root->right;
	}
	if(root==NULL)
	cout << "not found " << endl;
	else 
	cout << "found " << endl;
}
// Delete using Successor 
BST *deleteNode(BST *root, int data)
{
	if(root == NULL)
	{
		return root;
	}
	else if(data < root->data)
	{
		root->left = deleteNode(root->left,data);
	}
	else if(data > root->data)
	{
		root->right = deleteNode(root->right,data);
	}
	else{
		// CASE 1 : No child or Leaf Node
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		// CASE 2 : One Child Node 
		else if(root->left == NULL)
		{
			BST *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL)
		{
			BST *temp = root;
			root = root->left;
			delete temp;
		}
		// CASE 3 : Two Child
		else{
			BST *temp = root->right;
			while(temp->left != NULL)
			{
				temp = temp->left;
			}
			int Min = temp->data;
			root->data = temp->data;
			root->right = deleteNode(root->right,Min); 
		}
	}
	return root;
}
void print(BST *root)
{
	if(root==NULL)
	return;
	cout << root->data << " : ";
	if(root->left != NULL)
	{
		cout << "L = "<<root->left->data <<" , ";
	}
	if(root->right != NULL)
	{
		cout << "R = "<<root->right->data <<" , ";
	}
	cout << endl;
	print(root->left);
	print(root->right);
} 
// Delete Using Predecessor
BST *deleteNode1(BST *root, int data)
{
	if(root == NULL)
	return root;
	
	else if(data < root->data)
	root->left = deleteNode1(root->left,data);
	
	else if(data > root->data)
	root->right = deleteNode1(root->right,data);
	
	else{
		// CASE 1
		if(root->left == NULL && root->right == NULL)
		root = NULL;
		
		// CASE 2
		else if(root->left == NULL)
	    {
	    	BST *temp = root;
	    	root = root->right;
	    	delete temp;
		}
		
		else if(root->right == NULL)
	    {
	    	BST *temp = root;
	    	root = root->left;
	    	delete temp;
		}
		// CASE 3
		else{
			BST *temp = root->left;
			while(temp->right != NULL)
			   temp = temp->right;
		    
		    int Max = temp->data;
		    root->data = temp->data;
		    root->left = deleteNode1(root->left,Max);
		}
	}
}
int main()
{
	BST *root = NULL;
	cout << "Enter the number of elements that u want to insert ";
	int n; cin >> n;
	int data;
	for(int i = 0; i < n;i++)
	{
		cin >> data;
		root = insert(root,data);
	}
	Inorder(root);
	cout << endl;
	preorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	search(root,20);
	search(root,38);
	
	print(root);
	int value;
	cout << "Enter the Node that u want to delete : ";
	cin >> value;
//	root = deleteNode(root,value);	 // Delete using Successor 
	root = deleteNode1(root,value);  // Delete Using Predecessor
	print(root);
}
// 14 7 5 11 10 13 17 15 16 19 21 20

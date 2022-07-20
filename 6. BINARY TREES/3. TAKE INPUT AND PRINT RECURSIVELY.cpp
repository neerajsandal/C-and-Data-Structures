#include<iostream>
using namespace std;
template<class T>
class BinaryTree{
	public:
		T data;
		BinaryTree *left;
		BinaryTree *right;
		
		BinaryTree(T data)
		{
			this->data = data;
			left = right = NULL;
		}
		~BinaryTree()
		{
			delete left;
			delete right;
		}
};
  
  // take input in this way  1 2 -1 -1 3 -1 4 -1 -1  
  // 2 -1 -1 means both left and right child are NULL;
  // 3 -1  4 means left child of 3 is NULL and right child is 4
BinaryTree <int>* takeinput()
{
	cout << "Enter the data : ";
	int data;
	cin>>data;
	if(data == -1)
	{
		return NULL;
	}
	BinaryTree<int> *root = new BinaryTree<int>(data);
	BinaryTree<int> *leftchild = takeinput();
	BinaryTree<int> *rightchild = takeinput();
	root->left = leftchild;
	root->right = rightchild;
	
	return root;
}
void print(BinaryTree<int> *root)
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
		cout << "R = "<<root->right->data ;
	}
	cout << endl;
	print(root->left);
	print(root->right);
}
int main()
{
	BinaryTree<int> *root = takeinput();
	print(root);
}

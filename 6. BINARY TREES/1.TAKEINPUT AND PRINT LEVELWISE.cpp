#include<iostream>
#include<queue>
using namespace std;
template <class T>
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
BinaryTree<int> *takeinputLevelWise()
{
	cout << "Enter the root data : ";
	int rootdata;
	cin >> rootdata;
	
	BinaryTree<int> *root = new BinaryTree<int>(rootdata);
	queue<BinaryTree<int>*> pendingNodes;
	pendingNodes.push(root);
	
	while(!pendingNodes.empty())
	{
		BinaryTree<int> *front = pendingNodes.front();
		pendingNodes.pop();
		int leftchilddata;
		cout << "Enter the left child of " << front->data << endl;
		cin >> leftchilddata;
		
		if(leftchilddata != -1)
		{
			BinaryTree<int> *leftchild = new BinaryTree<int>(leftchilddata);
			pendingNodes.push(leftchild);
			front->left = leftchild;
		}
		
		int rightchilddata;
		cout << "Enter the right child of " << front->data << endl;
		cin >> rightchilddata;
		
		if(rightchilddata != -1)
		{
			BinaryTree<int> *rightchild = new BinaryTree<int>(rightchilddata);
			pendingNodes.push(rightchild);
			front->right = rightchild;
		}
	}
	return root;
}
void printLevelWise(BinaryTree<int> *root)
{
	if(root==NULL)
	{
		return ;
	}
	queue<BinaryTree<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty())
	{
		BinaryTree<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << front->data <<" : ";
		if(front->left != NULL)
		{
			cout << "L = " <<front->left->data <<" , ";
			pendingNodes.push(front->left);
		}
		if(front->right != NULL)
		{
			cout << "R = " <<front->right->data;
			pendingNodes.push(front->right);
		}
		cout << endl;
	} 
}
int countNodes(BinaryTree<int> *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int count = 0;
	count = 1 + countNodes(root->left) + countNodes(root->right);
	return count;
}
int main()
{
	BinaryTree<int> *root = takeinputLevelWise();
	printLevelWise(root);
	int n = countNodes(root);
	cout << "No. of Nodes : "<<n<<endl;
}

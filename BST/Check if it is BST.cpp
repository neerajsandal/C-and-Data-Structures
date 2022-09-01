#include <iostream>
#include <queue>
#include<climits>
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
bool BST(BinaryTreeNode<int> *root,int min,int max)
{
    if(root == NULL)
        return true;
    if(root->data < min)
        return false;
    if(root->data > max)
        return false;
    bool leftok = BST(root->left, min, root->data-1);  
    //  data of left child should be less than the root->data
    bool rightok = BST(root->right, root->data, max);
    // data of right child should be greater than or equal to root->data
    return leftok && rightok;
}
bool isBST(BinaryTreeNode<int> *root) {
	return BST(root,INT_MIN,INT_MAX);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}

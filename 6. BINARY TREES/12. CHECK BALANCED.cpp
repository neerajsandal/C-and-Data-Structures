#include <iostream>
#include <queue>

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
bool isBalanced(BinaryTreeNode<int> *root) {
    bool ans = false;
	if(root == NULL)
        return true;
    if(root->left != NULL && root->right != NULL)
    {
        ans = true;
    }
    else if(root->left!= NULL && root->right ==NULL)
    {
        return false;
    }
    else if(root->left == NULL && root->right != NULL)
    {
        return false;
    }
     ans = isBalanced(root->left) && isBalanced(root->right);
    if(ans)
        return true;
    return false;
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
    cout << (isBalanced(root) ? "true" : "false");
}

/*
Sample Input  :
1 2 3 -1 -1 -1 -1

Sample Output  :
true
*/

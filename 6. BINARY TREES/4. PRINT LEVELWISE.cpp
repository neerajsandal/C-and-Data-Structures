#include <iostream>
#include <queue>
using namespace std;
#include<queue>
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
void printLevelWise(BinaryTreeNode<int> *root) {
	if(root==NULL)
        return;
    queue<BinaryTreeNode<int>*> qn;
    qn.push(root);
    while(!qn.empty())
    {
        BinaryTreeNode<int> *front = qn.front();
        qn.pop();
        cout << front->data<<":";
        if(front->left!=NULL)
        {
            cout << "L:"<<front->left->data<<",";
            qn.push(front->left);
        }
        else{
            cout << "L:-1,";
        }
        if(front->right!=NULL)
        {
            cout<<"R:"<<front->right->data;
            qn.push(front->right);
        }
        else{
            cout<<"R:-1";
        }
        cout << endl;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}

/*
Sample Input 
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 
 Sample Output 
1:L:2,R:3
2:L:4,R:5
3:L:6,R:7
4:L:-1,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1
*/

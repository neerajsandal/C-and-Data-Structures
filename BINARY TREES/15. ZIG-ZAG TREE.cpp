/*
Given a binary tree, print the zig zag order. In zigzag order, 
level 1 is printed from left to right, level 2 from right to left 
and so on. This means odd levels should get printed from left to right
and even level right to left.
*/

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
void reverse(queue <BinaryTreeNode<int> *> &pn)
{
    if(pn.size() <= 1)
        return;
    BinaryTreeNode<int> *input = pn.front();
    pn.pop();
    reverse(pn);
    pn.push(input);
}
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    queue <BinaryTreeNode<int> *> pn;
    pn.push(root);
    int flag = 0;
    while(!pn.empty())
    {
        int n = pn.size();
        while(n != 0){
            BinaryTreeNode<int> *front = pn.front();
            pn.pop();
            cout << front->data << " ";
            if(flag == 0)
            {
                if(front->left != NULL)
                   pn.push(front->left);
                if(front->right != NULL)
                   pn.push(front->right);
            }
            else{
                if(front->right != NULL)
                   pn.push(front->right);
                if(front->left != NULL)
                   pn.push(front->left);
            }
            n--;
        }
        if(flag == 0){
            flag = 1;
        }
        else{
            flag = 0;
        }
        reverse(pn);
        cout << endl;
    }
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
    zigZagOrder(root);
}

#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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
class Pair{
    public:
    Node<int> *head;
    Node<int> *tail;
};
Pair helper(BinaryTreeNode<int>* root)
{
   if(root == NULL)
   {
       Pair p;
       p.head = p.tail = NULL;
       return p;
   }
    
    Pair leftNode = helper(root->left);
    Pair rightNode = helper(root->right);
    
    Node <int> *mid = new Node<int>(root->data);
    Pair output;
    
    if(leftNode.head != NULL)
    {
        output.head = leftNode.head;
        leftNode.tail->next = mid;
    }
    else{
        output.head = mid;
    }
    
    if(rightNode.head != NULL)
    {
        mid->next = rightNode.head;
        output.tail = rightNode.tail;
    }
    
    else{
        output.tail = mid;
    }
    return output;
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root)
{
    Pair output = helper(root);
    return output.head;
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
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) 
{
    vector<Node<int>*> vect;
    if(root == NULL)
    {
        vect.push_back(NULL);
        return vect;
    }
    queue<BinaryTreeNode<int>*> pn;
    pn.push(root);
    while(!pn.empty())
    {
        Node<int> *head = NULL;
        Node<int> *tail = NULL;
        int n = pn.size();
        while(n!=0)
        {
            BinaryTreeNode<int>* front = pn.front();
            pn.pop();
            Node<int> * temp = new Node<int> (front->data);
            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
            if(front->left != NULL){
                pn.push(front->left);
            }
            if(front->right!=NULL){
                pn.push(front->right);
            }
            n--;
        }
        vect.push_back(head);
    }
    return vect;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}

#include <iostream>
using namespace std;

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
class BST {
    BinaryTreeNode<int> *root;
   public:
    BST() { 
        root = NULL;
    }
    
    ~BST()
    {
          delete root;
    }
    private:
    void print(BinaryTreeNode<int>* Node)
    {
        if(Node == NULL)
            return;
        cout << Node->data << ":";
        if(Node->left != NULL)
        cout <<"L:" << Node->left->data <<",";
        if(Node->right!=NULL)
        cout << "R:" << Node->right->data;
        cout << endl;
        
        print(Node->left);
        print(Node->right);
    }
    
    bool search(BinaryTreeNode<int>* Node, int data)
    {
        if(Node == NULL)
            return false;
        if(Node->data == data)
            return true;
        bool left = search(Node->left,data);
            if(left == true)
                return left;
        bool right = search(Node->right,data);
            if(right == true)
                return right;
            else
                return false;
    }
    
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* Node, int data)
    { 
        if(Node == NULL)
        {
            BinaryTreeNode<int>* NewNode = new BinaryTreeNode<int>(data);
            return NewNode;
        }
        
        if(data <= Node->data)
        {
            Node->left = insert(Node->left,data);
        }
        else
        {
            Node->right = insert(Node->right,data);
        }
        return Node;
    }
    BinaryTreeNode<int> *minimum(BinaryTreeNode<int>* Node)
    {
        if(Node->left == NULL)
            return Node;
        BinaryTreeNode<int> *temp = minimum(Node->left);
        return temp;
    }
    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* Node, int data)
    {
        if(Node == NULL)
            return NULL;
        if(data < Node->data)
        {
            Node->left = remove(Node->left,data);
            return Node;
        }
        else if(data > Node->data)
        {
            Node->right = remove(Node->right,data);
            return Node;
        }
        else
        {
            if(Node->left == NULL && Node->right == NULL)
            {
                delete Node;
                return NULL;
            }
            else if(Node->left == NULL && Node->right != NULL)
            {
               BinaryTreeNode<int> *temp = Node->right;
               Node->right = NULL;
               delete Node;
               return temp;
            }
        
            else if(Node->left != NULL && Node->right == NULL)
            {
               BinaryTreeNode<int> *temp = Node->left;
               Node->left = NULL;
               delete Node;
               return temp;
            }
            
            else if(Node->left != NULL && Node->right != NULL)
            {
                BinaryTreeNode<int> *temp = minimum(Node->right);
                int mini = temp->data;
                Node->data = temp->data;

                Node->right = remove(Node->right,mini);
                return Node;
            }
        }    
    }
	/*----------------- Public Functions of BST -----------------*/
    public:
    void remove(int data) { 
        this->root = remove(this->root,data);
    }

    void print() { 
        print(root);
    }

    void insert(int data) { 
        this->root = insert(this->root,data);
    }

    bool search(int data) {
		return search(root,data); 
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}

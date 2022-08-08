BinaryTreeNode<int>* buildTree(int *preOrder, int preLength, int *inOrder, int inLength) {
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preOrder[0]);
    
    if(preLength == 1)     // base case when only root is present and no left or right node
        return root;
    if(preLength == 0)    //if one of both right or left is present check for 2, 1 2, 1 2;;;dry run it
        return NULL;
    
    int i = 0;
    
    while(inOrder[i] != preOrder[0]){
        i++;
    }
    
    int left_size = i;
    int right_size = inLength - i - 1;
    
    BinaryTreeNode<int> *leftSubtree = buildTree(preOrder + 1, left_size, inOrder, left_size);
    BinaryTreeNode<int> *rightSubtree = buildTree(preOrder + 1 + left_size, right_size, inOrder + 1 + left_size, right_size);
    
    root -> left = leftSubtree;
    root-> right = rightSubtree;
    
    return root;
}
 /*
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
2) Create a new tree node tNode with the data as the picked element. 
3) Find the picked element’s index in Inorder. Let the index be inIndex. 
4) Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
5) Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
6) return tNode.

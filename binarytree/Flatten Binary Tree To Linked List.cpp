// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

/*

Given a binary tree, flatten it to a linked list in-place.

Example :

Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.

*/


TreeNode* Solution::flatten(TreeNode* A) {
    if (!A)
        return A;
    TreeNode* root = A;
    
    while (A)
    {
        if (A->left)
        {
            TreeNode* rightSubTree = A->left;
            while (rightSubTree->right)
                rightSubTree = rightSubTree->right;
            rightSubTree->right = A->right;
            A->right = A->left;
            A->left = NULL;
        }
        A = A->right;
    }
    return root;
}

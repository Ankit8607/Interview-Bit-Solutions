// https://www.interviewbit.com/problems/valid-bst-from-preorder/

/*

Problem Description
 
 

You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.

Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.



Problem Constraints
1 <= A[i] <= 106

1 <= |A| <= 105



Input Format
First and only argument is an integer array A denoting the pre-order traversal.



Output Format
Return an integer:

0 : Impossible preorder traversal of a BST
1 : Possible preorder traversal of a BST


Example Input
Input 1:

A = [7, 7, 10, 10, 9, 5, 2, 8]


Example Output
Output 1:

 0
 
 */


struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
// Recursive function to build a BST from the given sequence in a preorder fashion
Node* buildTree(vector<int> const &seq, int &index, int min, int max)
{
    // Base case
    if (index == seq.size()) {
        return nullptr;
    }
 
    // Return if the next element of the given sequence is within the invalid range
    int val = seq[index];
    if (val < min || val > max) {
        return nullptr;
    }
 
    // Construct the root node and increment index
    Node* root = new Node(val);
    index++;
 
    // Since all elements in the left subtree of a BST must be less
    // than the root node's value, set range as `[min, val-1]` and recur
    root->left = buildTree(seq, index, min, val - 1);
 
    // Since all elements in the right subtree of a BST must be greater
    // than the root node's value, set range as `[val+1…max]` and recur
    root->right = buildTree(seq, index, val + 1, max);
 
    // return root node
    return root;
}
 
// Function to check if a given sequence represents the preorder traversal of a BST
bool isBST(vector<int> const &seq)
{
    /* 1. Construct the BST from the given sequence in a preorder fashion */
 
    // stores index of the next unprocessed node in the sequence
    int index = 0;
 
    // set the root node's range as [-INFINITY, INFINITY] and recur
    Node* root = buildTree(seq, index, INT_MIN, INT_MAX);
 
    /* 2. Just check if the whole sequence is traversed or not */
    return index == seq.size();
}
 
int Solution::solve(vector<int> &A) {
    return isBST(A);
}

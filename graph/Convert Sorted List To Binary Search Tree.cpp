// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

/*

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

A height balanced BST : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example :


Given A : 1 -> 2 -> 3
A height balanced BST  :

      2
    /   \
   1     3

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 TreeNode *fun(int l,int r,vector<int>&arr){
     if(l>r) return NULL;
     
     int mid=(l+r)/2;
     TreeNode *root=new TreeNode(arr[mid]);
     root->left=fun(l,mid-1,arr);
     root->right=fun(mid+1,r,arr);
     return root;
 }
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>arr;
    while(A){
        arr.push_back(A->val);
        A=A->next;
    }
    return fun(0,arr.size()-1,arr);
}

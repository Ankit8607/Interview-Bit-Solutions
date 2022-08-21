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

 TreeNode *fun(ListNode *head){
     if(!head ) return NULL;
     
    ListNode *prev=NULL,*slow=head,*fast=head;
    while(fast and fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    TreeNode *root=new TreeNode(slow->val);
    if(prev) prev->next=NULL;
    root->left=(head!=slow?fun(head):NULL);
    root->right=fun(slow->next);
    return root;
 }
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    return fun(A);
}


//  TreeNode *fun(int l,int r,vector<int>&arr){
//      if(l>r) return NULL;
     
//      int mid=(l+r)/2;
//      TreeNode *root=new TreeNode(arr[mid]);
//      root->left=fun(l,mid-1,arr);
//      root->right=fun(mid+1,r,arr);
//      return root;
//  }
 
// TreeNode* Solution::sortedListToBST(ListNode* A) {
//     vector<int>arr;
//     while(A){
//         arr.push_back(A->val);
//         A=A->next;
//     }
//     return fun(0,arr.size()-1,arr);
// }

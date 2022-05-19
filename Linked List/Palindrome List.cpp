// https://www.interviewbit.com/problems/palindrome-list/

/*

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *head;
int ans;

void rec(int level,ListNode *it,int n){
    if(level==n) return;

    rec(level+1,it->next,n);

    if(level<n/2) return;
    if(head->val!=it->val) ans=0;
    head=head->next;
}

int Solution::lPalin(ListNode* A) {
    if(!A || A->next==NULL) return 1;
    ListNode *it=A;
    head=A;
    int n=0;   
    while(it){
        n++;
        it=it->next;
    }
    it=A;
    ans=1;
    rec(0,it,n);
    return ans;
}

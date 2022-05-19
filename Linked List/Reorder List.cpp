// https://www.interviewbit.com/problems/reorder-list/

/*

Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,

Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
void rec(int level,int n,ListNode *it){
    
    if(level==n-1){
        return;
    }

    rec(level+1,n,it->next);

    if(level<n/2) return;

    ListNode *tmp=head->next;
    head->next=it->next;
    it->next->next=tmp;
    it->next=NULL;
    head=tmp;
}

ListNode* Solution::reorderList(ListNode* A) {
    ListNode *it;
    head=A;
    int n=0;
    it=A;
    while(it){
        n++;
        it=it->next;
    }
    if(n<=2) return A;
    it=A;
    rec(0,n,it);
    return A;
}

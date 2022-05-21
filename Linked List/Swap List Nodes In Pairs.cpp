// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,

Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *it=A,*prev=NULL;
    while(it and it->next){
        if(prev==NULL){
            prev=A;
            A=prev->next;
            prev->next=A->next;
            A->next=prev;
        }
        else{
            ListNode *tmp=it->next;
            prev->next=tmp;
            it->next=tmp->next;
            tmp->next=it;
            prev=it;
        }
        it=prev->next;
    }
    return A;
}

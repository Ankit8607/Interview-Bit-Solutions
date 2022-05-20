// https://www.interviewbit.com/problems/merge-two-sorted-lists/

/*

Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *head=NULL,*it=NULL;
    while(A and B){
        if(A->val<=B->val){
            if(head==NULL){
                head=A;
                it=A;
            }
            else{
                it->next=A;
                it=it->next;
            }
            A=A->next;
        }
        else{
            if(head==NULL){
                head=B;
                it=B;
            }
            else{
                it->next=B;
                it=it->next;
            }
            B=B->next;
        }
    }
    while(A){
        it->next=A;
        it=it->next;
        A=A->next;
    }
    while(B){
        it->next=B;
        it=it->next;
        B=B->next;
    }
    return head;
}

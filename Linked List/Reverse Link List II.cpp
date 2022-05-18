  // https://www.interviewbit.com/problems/reverse-link-list-ii/

/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:

Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:

Given m, n satisfy the following condition:

1 ≤ m ≤ n ≤ length of list.

Note 2:

Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B==C) return A;
    ListNode *head=A,*start=A,*it=A,*prev=A;
    
    for(int i=1;i<B;i++){
        prev=it;
        it=it->next;
    }
    start=it;
    ListNode *one=NULL,*two=it;
    for(int i=B;i<=C;i++){
        it=it->next;
        if(one){
            two->next=one;
        }
        one=two;
        two=it;
    }
    start->next=it;
    if(start==head) return one;
    else{
        prev->next=one;
        return head;
    }
}

// https://www.interviewbit.com/problems/intersection-of-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode *a=A,*b=B;
    while(a and b){
        a=a->next;
        b=b->next;
    }
    int len=0;
    while(a) A=A->next,a=a->next;
    while(b) B=B->next,b=b->next;
    
    while(A and B and A!=B){
        A=A->next;
        B=B->next;
    }
    
    if(A==B) return A;
    return NULL;
}

// https://www.interviewbit.com/problems/sort-list/

/*

Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* merge(ListNode* A, ListNode* B){
    if(A == NULL){
        return B;
    }
    if(B == NULL){
        return A;
    }
    
    ListNode* head = NULL;
    
    if(A->val < B->val){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    
    ListNode* temp = head;
    
    while(A != NULL && B != NULL){
        if(A->val < B->val){
            temp->next = A;
            A = A->next;
        }
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    
    if(A != NULL){
        temp->next = A;
    }
    else{
        temp->next = B;
    }
    
    return head;
} 

ListNode* Solution::sortList(ListNode* A) {
    ListNode *head=A;
    if(!head || head->next==NULL) return head;

    ListNode* start = A;
    ListNode* end = A->next;
    
    while(end != NULL && end->next != NULL){
        start = start->next;
        end = (end->next)->next;
    }
    
    end = start->next;
    start->next = NULL;
    
    return merge(sortList(head),sortList(end));
}

// https://www.interviewbit.com/problems/insertion-sort-list/

/*

Sort a linked list using insertion sort.

We have explained Insertion Sort at Slide 7 of Arrays

Insertion Sort Wiki has some details on Insertion Sort as well.

Example :

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void rec(ListNode* head){
    ListNode *it=head;
    int mn=head->val;
    while(it){
        mn=min(mn,it->val);
        it=it->next;
    }
    if(head->val==mn) return;
    it=head;
    while(it){
        if(it->val==mn){
            break;
        }
        it=it->next;
    }
    it->val=head->val;
    head->val=mn;
}

ListNode* Solution::insertionSortList(ListNode* head) {
    ListNode *it=head;
    while(it){
        rec(it);
        it=it->next;
    }
    return head;
}

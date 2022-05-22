// https://www.interviewbit.com/problems/rotate-list/

/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int K) {
    if(!head || head->next==NULL) return head;
    if(!K) return head;

    int n = 0;
    ListNode *cur = head;
    ListNode *last = head;

    while(cur) {
        n++;
        last = cur;
        cur = cur->next;
    }

    K %= n;

    cur = head;

    for(int i = 0; i < n - K - 1; i++)
        cur = cur->next;

    last->next = head;

    ListNode *temp = cur->next;
    cur->next = NULL;

    return temp;
}

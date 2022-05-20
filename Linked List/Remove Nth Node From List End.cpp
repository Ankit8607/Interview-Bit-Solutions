// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.

*/


ListNode* removeNthFromEnd(ListNode* head, int N) {
    if(!head) return head;

    ListNode *prev = NULL, *cur = head;

    for(int i = 0; i < N; i++) 
        cur = cur->next;

    if(!cur) return head->next;

    while(cur) {
        cur = cur->next;
        if(prev) prev = prev->next;
        else prev = head;
    }

    prev->next = prev->next->next;

    return head;
}

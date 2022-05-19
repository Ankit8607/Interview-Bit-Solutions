// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A || A->next==NULL) return A;
    ListNode *it=A;
    ListNode *head=NULL,*var=NULL;
    while(it){
        int flag=0;
        while(it->next and (it->val==it->next->val)){
            it->next=it->next->next;
            flag=1;
        }
        if(flag==0){
            if(!head) head=new ListNode(it->val), var=head;
            else var->next=new ListNode(it->val), var=var->next;
        }
        it=it->next;
    }
    return head;
}

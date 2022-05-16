// https://www.interviewbit.com/problems/partition-list/

/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,

Given 1->4->3->2->5->2 and x = 3,

return 1->2->2->4->3->5.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *head=NULL,*prev=NULL,*prev2=NULL,*tail=NULL;
    ListNode *it=A;
    while(it){
        ListNode *p= new ListNode(it->val);
        if(it->val<B){
            if(!head){
                head=p;
            }
            else prev->next=p;
            prev=p;
        }
        else{
            if(!tail){
                tail=p;
            }
            else prev2->next=p;
            prev2=p;
        }
        it=it->next;
    }
    if(head==NULL) return tail;
    prev->next=tail;
    return head;
}

// https://www.interviewbit.com/problems/even-reverse/

/*

Problem Description

Given a linked list A , reverse the order of all nodes at even positions.



Problem Constraints
1 <= Size of linked list <= 100000



Input Format
First and only argument is the head of the Linked-List A.



Output Format
Return the head of the new linked list.



Example Input
Input 1:

A = 1 -> 2 -> 3 -> 4
Input 2:

A = 1 -> 2 -> 3


Example Output
Output 1:

 1 -> 4 -> 3 -> 2
Output 2:

 1 -> 2 -> 3


Example Explanation
Explanation 1:

Nodes are positions 2 and 4 have been swapped.
Explanation 2:

No swapping neccassary here.


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::solve(ListNode* A) {
    if(!A || A->next==NULL) return A;
    ListNode *head=NULL,*it=A,*prev;
    while(it and it->next){
        it=it->next;
        if(!head) head=new ListNode(it->val);
        else{
            prev=new ListNode(it->val);
            prev->next=head;
            head=prev;
        }
        it=it->next;
    }

    it=A;
    while( head){
        it=it->next;
        it->val=head->val;
        head=head->next;
        it=it->next;
    }
    return A;
}

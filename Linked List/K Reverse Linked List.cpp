// https://www.interviewbit.com/problems/k-reverse-linked-list/

/*

Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) 
{
    ListNode* prev=NULL;
    ListNode* curr=A;
    ListNode* nxt;
    int cnt=0;
    while(curr!=NULL && cnt<B)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        cnt++;
    }
    if(nxt!=NULL)
    {
        A->next=reverseList(nxt,B);
    }
    return prev;
}




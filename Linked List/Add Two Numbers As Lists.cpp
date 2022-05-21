// https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/*

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int carry=0;
    ListNode *a=A,*b=B;
    while(a && b){
        carry+=a->val+b->val;
        a->val=carry%10;
        b->val=carry%10;
        carry/=10;
        a=a->next;
        b=b->next;
    }
    while(a){
        carry+=a->val;
        a->val=carry%10;
        carry/=10;
        if(!a->next){
            if(carry){
                a->next=new ListNode(carry);
            }
            return A;
        }
        a=a->next;
    }
    while(b){
        carry+=b->val;
        b->val=carry%10;
        carry/=10;
        if(!b->next){
            if(carry){
                b->next=new ListNode(carry);
            }
            return B;
        }
        b=b->next;
    }
    ListNode *it=A;
    while(it){
        if(it->next==NULL){
            if(carry) it->next=new ListNode(carry);
            return A;
        }
    }
}

// https://www.interviewbit.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    set<pair<int,ListNode*>>st;
    for(auto i: A) st.insert({i->val,i});
    
    ListNode *head=NULL,*root;
    while(!st.empty()){
        auto k=*st.begin();
        ListNode *t=k.second;
        if(head==NULL) head=t;
        else root->next=t;
        root=t;
        if(t->next!=NULL) st.insert({t->next->val,t->next});
        st.erase({t->val,t});
    }
    return head;
}

// https://www.interviewbit.com/problems/word-break/

class node {
public:
    node* arr[26];
    int end;
    node(){
        end = 0;
        for (int i=0;i<26;i++) {
            arr[i] = NULL;
        }
    }
};

void build (string& s, node* root) {
    node* head = root;
    for (auto i:s) {
        if ( head->arr[i- 'a'] == NULL) {
            head->arr[i-'a'] = new node();
        }
        head = head->arr[i-'a'];
    }
    head->end = 1;
}

void func ( int idx, string& s, node* root, vector<int>& dp) {
    for (int i=idx;i<s.size();i++) {
        if (root->arr[s[i]-'a'] != NULL) {
            root = root->arr[s[i] - 'a'];
            if ( root->end == 1) dp[i+1] = 1;
        }
        else return;
    }
}

int Solution::wordBreak(string s, vector<string> &arr) {
    const int n = s.size();
    node* root = new node();
    for (string& str : arr) {
        build(str,root);
    }
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for (int i=0;i<n;i++)
    {
        if (dp[i] == 1) func(i,s,root,dp);
    }
    // for (auto i : dp) cout<<i<<" ";
    // cout<<endl;
    return dp[n];
}

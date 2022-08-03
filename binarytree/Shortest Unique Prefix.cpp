// https://www.interviewbit.com/problems/shortest-unique-prefix/

/*

Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
NOTE : Assume that no word is prefix of another. In other words, the representation is always possible.

*/


class Node{
  public:
  Node* arr[26]={0};
  int cnt=0;
};

void build(Node *root,string s){
    for(char ch:s){
        int idx=ch-'a';
        if(root->arr[idx]==NULL) root->arr[idx]=new Node;
        root=root->arr[idx];
        root->cnt++;
    }
}

string get(Node *root,string s){
    string cur="";
    for(char ch:s){
        cur+=ch;
        int idx=ch-'a';
        root=root->arr[idx];
        if(root->cnt==1) return cur;
    }
    return cur;
}

vector<string> Solution::prefix(vector<string> &A) {
    Node *root=new Node;
    for(auto i:A) build(root,i);
    vector<string>res;
    for(auto i:A){
        res.push_back(get(root,i));
    }
    return res;
}

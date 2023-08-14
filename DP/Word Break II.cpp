// https://www.interviewbit.com/problems/word-break-ii/discussion/p/trie-dp-recursion/327384/427/

struct TrieNode{
    bool isEnd;
    TrieNode* child[26];
};

class Trie{
private:
    TrieNode* node;
public:
    Trie(){
        node = new TrieNode();
    }
    bool search(string s){
        TrieNode* cur = node;
        for(char c:s){
            if(cur->child[c-'a'] == NULL) return false;
            cur = cur->child[c-'a'];
        }
        return cur->isEnd;
    }
    void insert(string s){
        TrieNode* cur = node;
        for(char c:s){
            if(cur->child[c-'a'] == NULL) cur->child[c-'a'] = new TrieNode();
            cur = cur->child[c-'a'];
        }
        cur->isEnd = true;
    }
};

vector<string> recFun(string A, Trie* myTrie, int index, vector<vector<string>> &cache){
    vector<string> answer;
    if(index == A.size()){
        string str = "";
        answer.push_back(str);
        return answer;
    }
    if(cache[index].size()){
        return cache[index];
    }
    string str = "";
    for(int i=index; i<min(int(A.size()), index+21); i++){
        str += A[i];
        if(myTrie->search(str)){
            for(auto s:recFun(A, myTrie, i+1, cache)){
                if(i+1 == A.size()){
                answer.push_back(str + s);
                }
                else{
                answer.push_back(str + " " + s);                    
                }
            }
        }
    }
    return cache[index] = answer;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    vector<vector<string>> cache(A.size()+1);
    Trie* myTrie = new Trie();
    for(auto s:B){
        myTrie->insert(s);
    }
    //sort  
    return recFun(A, myTrie, 0, cache);
}

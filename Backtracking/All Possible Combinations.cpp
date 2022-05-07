/*

void rec(int level,vector<string> &A,vector<string> &ans,string s){
    if(level==A.size()){ 
        ans.push_back(s);
        return;
    }
    
    for(int i=0;i<A[level].size();i++){
        rec(level+1,A,ans,s+A[level][i]);
    }
}

vector<string> Solution::specialStrings(vector<string> &A) {
    vector<string>ans;
    string s="";
    rec(0,A,ans,s);
    return ans;
}


*/


void rec(int level,vector<string> &A,vector<string> &ans,string s){
    if(level==A.size()){ 
        ans.push_back(s);
        return;
    }
    
    for(int i=0;i<A[level].size();i++){
        rec(level+1,A,ans,s+A[level][i]);
    }
}

vector<string> Solution::specialStrings(vector<string> &A) {
    vector<string>ans;
    string s="";
    rec(0,A,ans,s);
    return ans;
}

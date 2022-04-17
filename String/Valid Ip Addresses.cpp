/*

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)

*/


// This function will check if string s is a valid IP or not
bool valid_ip(string &s){ 
    // Just Brute Force: Four for loops to check for each number separated by "."
    int x=0,i=0,flag=0; 
    for(;s[i]!='.';i++){
        if(x==0&&s[i]=='0'){
            if(flag) return false;
            flag=1;
        }
        x = x*10 + (s[i]-'0');
    }
    if(flag&&x!=0) return 0;
    if(x<0||x>255||(x==0&&flag==0)) return 0;
    x=0,i++,flag=0; 
    for(;s[i]!='.';i++){
        if(x==0&&s[i]=='0'){
            if(flag) return false;
            flag=1;
        }
        x = x*10 + (s[i]-'0');
    }
    if(flag&&x!=0) return 0;
    if(x<0||x>255||(x==0&&flag==0)) return 0;
    x=0,i++,flag=0; 
    for(;s[i]!='.';i++){
        if(x==0&&s[i]=='0'){
            if(flag) return false;
            flag=1;
        }
        x = x*10 + (s[i]-'0');
    }
    if(flag&&x!=0) return 0;
    if(x<0||x>255||(x==0&&flag==0)) return 0;
    x=0,i++,flag=0; 
    for(;s[i];i++){
        if(x==0&&s[i]=='0'){
            if(flag) return false;
            flag=1;
        }
        x = x*10 + (s[i]-'0');
    }
    if(flag&&x!=0) return 0;
    if(x<0||x>255||(x==0&&flag==0)) return 0;
    return 1;
}
void solve(string A,int cnt,vector<string>&ans,int st){
    // You just have to put three dots, somewhere in between the String.
    if(cnt==3){
        if(valid_ip(A)) ans.push_back(A); // If A is valid IP
        return;
    }
    for(int i=st;i<A.size();i++){
        A.insert(A.begin()+i,'.');
        solve(A,cnt+1,ans,i+1);
        A.erase(A.begin()+i);
    }
}
vector<string> Solution::restoreIpAddresses(string A){
    vector<string>ans;
    // Call your recursive function
    solve(A,0,ans,0);
    // Sort your result
    sort(ans.begin(),ans.end());
    return ans;
}

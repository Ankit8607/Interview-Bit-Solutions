// https://www.interviewbit.com/problems/stepping-numbers/

/*

Problem Description

Given A and B you have to find all stepping numbers in range A to B.

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

e.g. 123 is stepping number, but 358 is not a stepping number



Input Format
First argument is an integer A.

Second argument is an integer B.



Output Format
Return a integer array sorted in ascending order denoting the stepping numbers between A and B.



Example Input
Input 1:

 A = 10
 B = 20


Example Output
Output 1:

 [10, 12]


Example Explanation
Explanation 1:

 All stepping numbers are 10 , 12 
 
 */


void rec(int digit,int A,int B,int num,vector<int>&ans){
    if(num>=A and num<=B) ans.push_back(num);
    if(num>B) return;
    
    if(digit>=1) rec(digit-1,A,B,num*10+digit-1,ans);
    if(digit<9) rec(digit+1,A,B,num*10+digit+1,ans);
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int>ans;
    for(int i=1;i<10;i++){
        rec(i,A,B,i,ans);
    }
    if(A==0) ans.push_back(0);
    sort(ans.begin(),ans.end());
    return ans;
}

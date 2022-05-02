/*

Problem Description
 
 

Given a string A and integer B, what is maximal lexicographical string that can be made from A if you do atmost B swaps.



Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5



Input Format
First argument is string A.

Second argument is integer B.



Output Format
Return a string, the naswer to the problem.



Example Input
Input 1:

A = "254"
B = 1
Input 2:

A = "254"
B = 2


Example Output
Output 1:

 524
Output 2:

 542


Example Explanation
Explanation 1:

 Swap 2 and 5.
Explanation 2:

Swap 2 and 5 then swap 4 and 2.

*/


void swap(char &amp;a,char &amp;b)
{
    char c=a; a=b; b=c;
}

string ans;
int n;

void check(int i,string &amp;str,int k)
{
    if(ans&lt;str)
    ans=str;
    
    if(!k || i==n)
    return;
    
    check(i+1,str,k);

    for(int j=i+1;j&lt;n;j++)
    {
        if(str[j]&gt;str[i])
        {
            swap(str[j],str[i]); 
            check(i+1,str,k-1);
            swap(str[j],str[i]); 
        }
    }
}
string Solution::solve(string str, int k) 
{
     ans=str;
    n=str.length();
    
     check(0,str,k);
     return ans;
}




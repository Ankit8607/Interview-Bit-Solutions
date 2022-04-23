/*

Problem Description

Given an array A of positive integers,call a (contiguous,not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly B.

(For example: [1, 2, 3, 1, 2] has 3 different integers 1, 2 and 3)

Return the number of good subarrays of A.



Problem Constraints
1 <= |A| <= 40000

1 <= A[i] <= |A|

1 <= B <= |A|



Input Format
The first argument given is the integer array A.

The second argument given is an integer B.



Output Format
Return an integer denoting the number of good subarrays of A.



Example Input
Input 1:

 A = [1, 2, 1, 2, 3]
 B = 2
Input 2:

 A = [1, 2, 1, 3, 4]
 B = 3


Example Output
Output 1:

 7
Output 2:

 3


Example Explanation
Explanation 1:

  Subarrays formed with exactly 2 different integers: [1, 2], [2, 1], [1, 2], [2, 3], [1, 2, 1], [2, 1, 2], [1, 2, 1, 2].
Explanation 2:

  Subarrays formed with exactly 3 different integers: [1, 2, 1, 3], [2, 1, 3], [1, 3, 4].
  
  *
  
  // Mine approach
  
  int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    int cnt[100000]={0},cntk[100000]={0};
    int ans=0;
    int i=0,j=0,diff=0;
    int k=i;
    while(j<n){
        k=i;
        while(j<n and (diff<B || cnt[A[j]]>0)){
            if(cnt[A[j]]==0) diff++;
            cnt[A[j]]++;
            cntk[A[j]]++;
            j++;
            if(diff==B){
                while(cntk[A[k]]>1)cntk[A[k]]--,k++;
                ans+=(k-i)+1;
            }
        }
        while(diff>=B){
            if(cnt[A[i]]==1) diff--;
            cnt[A[i]]--;
            if(i==k)cntk[A[k]]--,k++;
            i++; 
        } 
    }
    return ans;
}


//Smart approach

int at_most(vector<int> A,int k){
    int n = A.size(),s = 0,ans = 0,j = 0,i = 0;
    unordered_map<int,int> mp;
    while(j < n){
        mp[A[j]]++;
        while(mp.size() > k){
            mp[A[i]]--;
            if(mp[A[i]] == 0) mp.erase(A[i]);
            i++;
        }
        ans += (j-i+1);
        j++;
    }
    return ans;
}

int Solution::solve(vector<int> &A, int B) {
    return at_most(A,B)-at_most(A,B-1);
}

/*


You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.

Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

*/


vector<int> Solution::maxone(vector<int> &A, int B) {
    int n=A.size();
    vector<int>res;
    int i=0,j=0,cnt=B,len=0,ans=0;
    while(j<n){
        while(j<n and (cnt || A[j]==1)){
            if(A[j]==0) cnt--;
            j++;
            len++;
        }
        if(len>ans){
            vector<int>tmp;
            for(int k=i;k<j;k++) tmp.push_back(k);
            ans=len;
            res=tmp;
        }
        if(A[i]==0) cnt++;
        len--;
        i++;
    }
    return res;
}

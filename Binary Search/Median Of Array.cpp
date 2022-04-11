/*

There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. 

For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5

*/


// double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
//     int n=A.size(),m=B.size();
//     int lo=min((n>0?A[0]:1e9),(m>0?B[0]:1e9));
//     int hi=max((n>0?A[n-1]:-1e9),(m>0?B[m-1]:-1e9));
//     int tar=(m+n)/2+(m+n)%2;
//     while(lo<=hi){
//         int mid=(lo+hi)/2;
//         int cnt=upper_bound(A.begin(),A.end(),mid)-A.begin();
//         int ans=1e9;
//         if(cnt<n)ans=min(A[cnt],ans);
//         int mi=upper_bound(B.begin(),B.end(),mid)-B.begin();
//         if(mi<m)ans=min(B[mi],ans);
//         cnt+=mi;
//         if(cnt<tar) lo=mid+1;
//         else if(cnt>tar) hi=mid-1;
//         else{
//             // cout<<"mid= "<<mid<<" ";
//             if((m+n)%2) return mid;
//             else{
//                 // int mi=upper_bound(A.begin(),A.end(),mid)-A.begin();
//                 // cout<<"ans= "<<ans<<" ";
//                 // mi=upper_bound(B.begin(),B.end(),mid)-B.begin();
//                 // cout<<"ans2= "<<ans<<" ";
//                 return (mid+ans)/2.0;
//             }
//         }
//     }
// }

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int N1 = A.size();
    int N2 = B.size();
    if (N1 < N2) return findMedianSortedArrays(B, A);   
    if (N2 == 0) return (A[(N1-1)/2] + (double)A[N1/2])/2.0;

    int lo = 0, hi = N2 * 2,mid1,mid2;
    double L1,L2,R1,R2;
    while (lo <= hi) {
         mid2 = (lo + hi) / 2;  
         mid1 = N1 + N2 - mid2; 

         L1 = (mid1 == 0) ? -1000000000 : A[(mid1-1)/2]; 
         L2 = (mid2 == 0) ? -1000000000 : B[(mid2-1)/2];
         R1 = (mid1 == N1 * 2) ? 1000000000 : A[(mid1)/2];
         R2 = (mid2 == N2 * 2) ? 1000000000 : B[(mid2)/2];

        if (L1 > R2) lo = mid2 + 1;    
        else if (L2 > R1) hi = mid2 - 1;    
        else return (max(L1,L2) + min(R1, R2)) / 2;
    }
    return -1;
}

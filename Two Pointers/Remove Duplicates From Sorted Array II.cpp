/*

Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,

Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].

*



int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=1,j=1,n=A.size();
    int freq=1;
    while(j<n){
        if(A[j]!=A[j-1]){
            freq=1;
            A[i]=A[j];
            i++;
        }
        else{
            if(freq==1){
                freq=2;
                A[i]=A[j];
                i++;
            }
        }
        j++;
    }
    return i;
}

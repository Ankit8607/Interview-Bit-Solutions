/*

Given an array with n objects colored red, white or blue, 

sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]

*/


void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int red=0,blue=0,white=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0) red++;
        else if(A[i]==1) white++;
        else blue++;
    }
    for(int i=0;i<red;i++) A[i]=0;
    for(int i=red;i<red+white;i++)A[i]=1;
    for(int i=red+white;i<A.size();i++) A[i]=2;
}


    // int i=0,j=A.size()-1,k=0;
    // while(i<=j)
    // {
    //     if(A[i]==2)
    //     {
    //         swap(A[i],A[j]);
    //         j--;
    //     }
    //     else if(A[i]==0)
    //     {
    //         swap(A[i],A[k]);
    //         i++;
    //         k++;
    //     }
    //     else i++;
    // }

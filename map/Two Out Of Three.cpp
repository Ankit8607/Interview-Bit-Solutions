// https://www.interviewbit.com/problems/two-out-of-three/

/*

Problem Description

Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.



Problem Constraints
1 <= |A|, |B|, |C| <= 100000

1 <= A[i], B[i], C[i] <= 100000

A, B, C may or may not have pairwise distinct elements.



Input Format
First argument is the array A.

First argument is the array B.

First argument is the array C.



Output Format
Return a sorted array of numbers.



Example Input
Input 1:

A = [1, 1, 2]
B = [2, 3]
C = [3]
Input 2:

A = [1, 2]
B = [1, 3]
C = [2, 3]


Example Output
Output 1:

[2, 3]
Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

1 is only present in A. 2 is present in A and B. 3 is present in B and C.
Explanation 2:

All numbers are present in atleast 2 out of 3 lists.

*/


vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int, int> mp;

    // setting the first bit from the right end to 1 if it is present in A
    for(int &i : A)
    {
        mp[i] = 1;
    }

    // setting the second bit from the right end to 1 if it is present in B
    for(int &i : B)
    {
        if(mp.find(i) != mp.end())
            mp[i] |= (1<<1);
        else
            mp[i] = 2;
    }

    // setting the third bit from the right end to 1 if it is present in C
    for(int &i : C)
    {
        if(mp.find(i) != mp.end())
            mp[i] |= (1<<2);
        else
            mp[i] = 4;
    }

    vector<int> res;
    for(auto &i : mp)
    {
        // present in atleast two of them : 011 101 110 111
        if(i.second == 3 || i.second == 5 || i.second == 6 || i.second == 7)
            res.push_back(i.first);
    }

    return res;
}




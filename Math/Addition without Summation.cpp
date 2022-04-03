/*
You are given two numbers A and B.

You have to add them without using arithmetic operators and return their sum.



Problem Constraints
1 <= A, B <= 109


Input Format
The first argument is the integer A. The second argument is the integer B.


Output Format
Return a single integer denoting their sum.


Example Input
Input 1:
A = 3
B = 10
Input 2:

A = 6
B = 1


Example Output
Output 1:
13
Output 2:

7


Example Explanation
Explanation 1:
3 + 10 = 13
Explanation 2:

6 + 1 = 7.
Note, you have to add without using arithmetic operators.

*/

int Add(int x, int y)
{
    // Iterate till there is no carry
    while (y != 0)
    {
        // carry should be unsigned to
        // deal with -ve numbers
        // carry now contains common
        //set bits of x and y
        unsigned carry = x & y;
 
        // Sum of bits of x and y where at
        //least one of the bits is not set
        x = x ^ y;
 
        // Carry is shifted by one so that adding
        // it to x gives the required sum
        y = carry << 1;
    }
    return x;
}

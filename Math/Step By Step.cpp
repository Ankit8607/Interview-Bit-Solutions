/*

Given a target A on an infinite number line, i.e. -infinity to +infinity.

You are currently at position 0 and you need to reach the target by moving according to the below rule:

In ith move you can take i steps forward or backward.
Find the minimum number of moves required to reach the target.



Problem Constraints
-109 <= A <= 109



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the minimum moves to reach target.



Example Input
Input 1:

 3
Input 2:

 2


Example Output
Output 1:

 2
Output 2:

 3


Example Explanation
Explanation 1:

 On the first move we step from 0 to 1.
 On the second step we step from 1 to 3.
Explanation 2:

 On the first move we step from 0 to 1.
 On the second move we step  from 1 to -1.
 On the third move we step from -1 to 2.
 
 */


int Solution::solve(int A) 
{
    int target = abs(A);

int n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);

int sum = n * (n + 1) / 2;

if (sum == target)

return n;


int d = sum - target;
if ((d & 1) == 0)
    return n;
else
    return n + ((n & 1) ? 2 : 1);




}

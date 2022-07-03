// https://www.interviewbit.com/problems/regular-expression-match/

/*

Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.

’?’ : Matches any single character.
‘*’ : Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return 0 or 1:
    => 0 : If the patterns do not match.
    => 1 : If the patterns match.
Constraints:

1 <= length(A), length(B) <= 9e4
Examples :

Input 1:
    A = "aa"
    B = "a"

Output 1:
    0

Input 2:
    A = "aa"
    B = "aa"

Output 2:
    1

Input 3:
    A = "aaa"
    B = "aa"

Output 3:
    0
    
Input 4:
    A = "aa"
    B = "*"

Output 4:
    1

Input 5:
    A = "aa"
    B = "a*"

Output 5:
    1

Input 6:
    A = "ab"
    B = "?*"

Output 6:
    1

Input 7:
    A = "aab"
    B = "c*a*b"

Output 7:
    0
    
    
*/



int Solution::isMatch(const string s, const string p) {
    int i = 0, j = 0;
    int n = (int)s.length();
    int m = (int)p.length();
    int laststar = -1, lasti = -1;

    while (i < n)
    {
        if (j < m && (p[j] == '?' || p[j] == s[i]))
        {
            i++;
            j++;
        }
        else if (j < m && p[j] == '*')
        {
            laststar = j;
            lasti = i;
            j++;
        }
        else if (laststar == -1)
            return false;
        else
        {
            j = laststar + 1;
            i = lasti + 1;
            lasti = i;
        }
    }

    for (int i = j; i < m; i++)
        if (p[i] != '*')
            return false;

    return true;
}

/*

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Input Format:

The first and the only argument contains N integers in an array A.
Output Format:

Return an integer, representing the minimum candies to be given.
Example:

Input 1:
    A = [1, 2]

Output 1:
    3

Explanation 1:
    The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
    So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

Input 2:
    A = [1, 5, 2, 1]

Output 2:
    7

Explanation 2:
    Candies given = [1, 3, 2, 1]
    
*/


int Solution::candy(vector<int> &ratings) {
    int candies = 0;
    int size = ratings.size();
    vector<int> lefttoright(size, 1);
    vector<int> righttoleft(size, 1);
    
    for (auto l = 1; l<size; ++l)
        if (ratings[l] > ratings[l-1])
            lefttoright[l] = lefttoright[l-1] + 1;
    
    for (auto r = size-2; r>=0; --r)
        if (ratings[r] > ratings[r+1])
            righttoleft[r] = righttoleft[r+1] + 1;
            
    for (auto i = 0; i<size; ++i)
        candies += max(lefttoright[i], righttoleft[i]);
        
    return candies;
}

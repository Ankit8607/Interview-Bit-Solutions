// https://www.interviewbit.com/problems/xor-between-two-arrays/

/*


Problem Description

Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.

Return this maximum xor value.



Problem Constraints
1 <= |A|, |B| <= 105

1 <= A[i], B[i] <= 109



Input Format
First argument is an integer array A.

Second argument is an integer array B.



Output Format
Return an integer denoting the maximum xor value as described in the question.



Example Input
Input 1:

 A = [1, 2, 3]
 B = [4, 1, 2]


Example Output
Output 1:

 7


Example Explanation
Explanation 1:

 Pick A[2] and B[0] because their xor value is maximum. 3 ^ 4 = 7
 
 */
 
 
 struct Node {
    Node* left;
    Node* right;
};

class MaxXorHelper{
  private : Node* root;    
  public :
    MaxXorHelper() {
        root = new Node();
    }

    void addElements(vector<int> &arr) {
        for(int i=0; i<arr.size(); i++) {
            Node* node = root;
            int val = arr[i];
            for(int j=31; j>=0; j--) {
                int bit = (val >> j) & 1;

                if(bit == 0) {
                    if(!node->left) {
                        node->left = new Node();
                    }
                    node = node->left;
                } 
                else {
                    if(!node->right) {
                        node->right = new Node();
                    }
                    node = node->right;
                }
            }
        }
    }

    int findMaxXor(vector<int> &arr) {
        int maxXor = INT_MIN;
        for(int i=0; i<arr.size(); i++) {
            Node* node = root;
            int val2 = 0;
            int val1 = arr[i];
            for(int j=31; j>=0; j--) {
                int bit = (val1 >> j) & 1;

                if(bit == 0) {
                    if(node->right) {
                        val2 |= (1 << j);
                        node = node->right;
                    } else{
                        node = node->left;
                    } 
                }
                else {
                    if(node->left) {
                        node = node->left;
                    } else{
                        val2 |= (1 << j);
                        node = node->right;
                    }
                }
            }
            int curXor = val1 ^ val2;
            maxXor = max(maxXor, curXor);
        }
        return maxXor;
    }
};

int Solution::solve(vector<int> &A, vector<int> &B) {
    MaxXorHelper helper;
    helper.addElements(A);
    return helper.findMaxXor(B);
}

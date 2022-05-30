// https://www.interviewbit.com/problems/points-on-the-straight-line/

/*

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])

*/


int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0 || B.size() == 0){
        return 0;
    }
    
    unordered_map<double, int> myMap;
    int sol = 1;
    for(int i = 0; i < A.size(); i++){
        int duplicate = 1;
        int vertical = 0;
        for(int j = i+1; j < A.size(); j++){
            if(A[i] == A[j]){
                if(B[i] == B[j]){
                    duplicate++;
                }
                else{
                    vertical++;
                }
            }
            else{
                double slope = 0.0;
                double x = A[j] - A[i];
                double y = B[j] - B[i];
                if(B[j] != B[i]){
                    slope = (1.0 * (y/x));
                }
                if(myMap.find(slope) != myMap.end()){
                    myMap[slope]++;
                }
                else{
                    myMap[slope] = 1;
                }
            }
        }
        auto it = myMap.begin();
        while(it != myMap.end()){
            int t = it->second;
            if((t + duplicate) > sol){
                sol = t + duplicate;
            }
            it++;
        }
        if((vertical + duplicate) > sol){
            sol = vertical + duplicate;
        }
        myMap.clear();
    }
    
    return sol;
}

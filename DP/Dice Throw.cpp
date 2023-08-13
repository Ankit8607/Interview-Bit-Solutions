// https://www.interviewbit.com/problems/dice-throw/discussion/p/c-easy-solution-using-prev-and-curr/406883/2622/

int Solution::findDiceSum(int A, int B, int C) {
//vector<vector<int>>dp(A+1,vector<int>(C+1,0));
   int N = 1e9+7;
   vector<long long int>prev(C+1,0);
   prev[0]=1;
   for(int i=1;i<=A;i++){
       vector<long long int>curr(C+1,0);
       for(int j=1;j<=C;j++){
           prev[j]+=prev[j-1];
           prev[j]=prev[j]%N;
       }
       for(int j=1;j<=C;j++){
           if(j-B-1>=0){
               curr[j]= ((prev[j-1]- prev[j-B-1])+N);
               curr[j]= curr[j]%N;
           }
           else{
               curr[j]= prev[j-1];
               curr[j]= curr[j]%N;
           }
       }
       prev=curr;
   }
   return prev[C];
}

// User function Template for C++

class Solution {
  public:
  
    int solveMemo(int n,vector<int> &dp){
        if(n<=1){
            return 0;
        }
        
        if(n==2){
            return 1;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=(n-1)*(countDer(n-1)+countDer(n-2));
        return dp[n];
        
    }
    int solveTab(int n){
        vector<int> dp(n+1,-1);
        dp[1]=0;
        dp[2]=1;
        
        for(int i=3;i<=n;i++){
            dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
        }
        return dp[n];
    }
    int solve(int n){
        vector<int> dp(n+1,-1);
        int prev2=0;
        int prev1=1;
        
        for(int i=3;i<=n;i++){
            dp[i]=(i-1)*(prev2+prev1);
            prev2=prev1;
            prev1=dp[i];
        }
        return dp[n];
    }
    int countDer(int n) {
    // vector<int> dp(n+1,-1);
    // return solveMemo(n,dp);
        return solveTab(n);
    }
class Solution {
  public:
  
    int solve(int n,int r,vector<vector<int>> &dp){
        if(n<r){
            return 0;
        }
        if(r==0){
            return 1;
        }
        if(dp[n][r]!=-1){
            return dp[n][r];
        }
        //include
        int include=solve(n-1,r-1,dp);
        //exclude
        int exclude=solve(n-1,r,dp);
        
        dp[n][r]=include+exclude;
        return dp[n][r];
    }
    
    int nCr(int n, int r) {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
        if(r>n){
            return 0;
        }
        return solve(n,r,dp);
        //nCr = n-1Cr-1 + n-1Cr
    }
};
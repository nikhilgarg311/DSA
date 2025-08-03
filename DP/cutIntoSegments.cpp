int solve(int n, int x, int y, int z,vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n]!=INT_MIN){
        return dp[n];
    }
    dp[n]= max(solve(n-x,x,y,z,dp),max(solve(n-y,x,y,z,dp),solve(n-z,x,y,z,dp)))+1;
    
    return dp[n];
    
    
}

int maximizeTheCuts(int n, int x, int y, int z) {
    // Your code here
    //int target=n;
    vector<int> dp(n+1,INT_MIN);
    int ans=solve(n,x,y,z,dp);
    if(ans<0){
        return 0;
    }
    return ans;
}
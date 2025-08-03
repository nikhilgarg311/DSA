class Solution {
public:
    int solve(vector<int>& coins, int amount,vector<int> &dp){
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount]!=-1){
            return dp[amount];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solve(coins,amount-coins[i],dp);
            if(ans!=INT_MAX){
                mini=min(mini,ans+1);
            }
        }
        dp[amount]=mini;
        return mini;

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans= solve(coins,amount,dp);
        if(ans!=INT_MAX){
            return ans;
        }
        return -1;
    }
};


////////////////--------------------/////////////////////
//tabulation method below

int solve(vector<int>& coins, int amount){
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        
        for(int j=1;j<=amount;j++){
            for(int i=0;i<coins.size();i++){
                if(j-coins[i]>=0 && dp[j-coins[i]]!=INT_MAX){
                    dp[j]=min(dp[j],1+dp[j-coins[i]]);
                }
                
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        return solve(coins,amount);
    }
class Solution {
public:
    int solve(vector<int>& cost, int n,vector<int> &dp ){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n]= min(solve(cost,n-1,dp),solve(cost,n-2,dp))+cost[n];
        return dp[n];
    }
    int solve2(vector<int>& cost, int n ){
        //vector<int> dp(n+1);
        int prev2= cost[0];
        int prev1=cost[1];
        int curr;
        for(int i=2;i<n;i++){
            curr=min(prev1,prev2)+cost[i];
            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // vector<int> dp(n+1,-1);
        // int res= min(solve1(cost,n-1),solve1(cost,n-2));
        // return res;
        int res=solve2(cost,n);
        return res;
    }
};
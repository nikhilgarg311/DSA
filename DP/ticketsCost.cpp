class Solution {
public:

    int solve(vector<int>& days, vector<int>& costs, int index,vector<int> &dp){
        
        if(index>=days.size()){
            return 0;
        }

        if(dp[index]!=INT_MAX){
            return dp[index];
        }
        int ans=INT_MAX;
        for(int i=0;i<costs.size();i++){
            if(i==0){
                int temp=index;
                while(temp<days.size() && days[temp]<days[index]+1){
                    temp++;
                }
                ans=min(ans,costs[0]+solve(days,costs,temp,dp));
            }
            else if(i==1){
                int temp=index;
                while(temp<days.size() && days[temp]<days[index]+7){
                    temp++;
                }
                ans=min(ans,costs[1]+solve(days,costs,temp,dp));
            }
            else if(i==2){
                int temp=index;
                while(temp<days.size() && days[temp]<days[index]+30){
                    temp++;
                }
                ans=min(ans,costs[2]+solve(days,costs,temp,dp));
            }
        }
        dp[index]=ans;
        return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        vector<int> dp(n+1,INT_MAX);

        return solve(days,costs,0,dp);
    }
};
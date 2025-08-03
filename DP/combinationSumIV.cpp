class Solution {
  public:
  
    int solveRec(vector<int>& arr,int target){
        
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        
       int ans=0;
       for(int i=0;i<arr.size();i++){
           ans+=solveRec(arr,target-arr[i]);
       }
       return ans;
       
    }
    
    int solveMemo(vector<int>& arr,int target,vector<int> &dp){
        
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        
        if(dp[target]!=-1){
            return dp[target];   
        }
        
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=solveMemo(arr,target-arr[i],dp);
        }
       dp[target]=ans;
       return dp[target];
       
    }
    
    int solveTab(vector<int>& arr,int target){
        vector<int> dp(target+1,0);
        dp[0]=1;
        
        int ans=0;
        for(int j=1;j<=target;j++){
            int ans=0;
            for(int i=0;i<arr.size();i++){
                if(j-arr[i]>=0){
                    ans+=dp[j-arr[i]];
                }
            }
            dp[j]=ans;
        }
        
        
        return dp[target];
    }
    
    
    int combinationSum4(vector<int>& arr, int key) {
        // complete the function here
        // int n=arr.size();
        // vector<int>dp(key+1,-1);
        // //return solveRec(arr,key);
        // return solveMemo(arr,key,dp);
        return solveTab(arr,key);
        
    }
};
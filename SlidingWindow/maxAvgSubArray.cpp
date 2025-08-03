class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi=INT_MIN;
        double sum=0;

        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxi=sum/k;

        for(int i=k;i<nums.size();i++){
            sum = sum - nums[i-k];
            sum = sum + nums[i];
            if(sum/k>maxi){
                maxi=sum/k;
            }
        }

        return maxi;

    }
};
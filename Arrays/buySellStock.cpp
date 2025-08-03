class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()==1){
            return 0;
        }
        int maxi=0;
        int buy=0,sell=1;

        while(sell<prices.size()){
            if(prices[sell]-prices[buy]<0){
                buy=sell;
                if(sell+1<prices.size()){
                    sell=sell+1;
                }
            }
            else{
                int profit= prices[sell]-prices[buy];
                maxi=max(maxi,profit);
                sell++;
            }
        }
        return maxi;
    }
};
class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        // code here
        map<int,int> m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int maxi=INT_MIN;
        int ans=maxi;
        for(auto i:m){
            if(i.second>=maxi){
                maxi=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};
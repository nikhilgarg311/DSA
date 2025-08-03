class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                q.push(arr[i]);
            }
        }
        
        if(!q.empty()){
            ans.push_back(q.front());
        }
        else{
            ans.push_back(0);
        }
        
        for(int i=k;i<arr.size();i++){
        
            if(arr[i-k]<0){
                q.pop();
            }
            if(arr[i]<0){
                q.push(arr[i]);
            }
            
            if(!q.empty()){
            ans.push_back(q.front());
            }
            else{
                ans.push_back(0);
            }
            
        }
        
        return ans;
    }
};
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int lo=0,mid=0,high=arr.size()-1;
        while(mid<=high){
            
            if(arr[mid]==0){
                swap(arr[mid],arr[lo]);
                lo++;mid++;
            }
            else if(arr[mid]==1){
                mid++;
            }
            else if(arr[mid]==2){
                swap(arr[mid],arr[high]);
                high--;
            }
        }
    }
};
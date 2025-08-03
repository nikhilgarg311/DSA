class Solution {
  public:
  
    void heapify(vector<int> & arr, int i,int n){
        
        int largest=i;
        int left= 2*i+1;
        int right= 2*i+2;
        
        if(left<n && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<n && arr[largest]<arr[right]){
            largest=right;
        }
        
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
        
        return;
        
        
    }
    
    void heapSort(vector<int> &arr,int n){
        int size=n;
        
        while(size>1){
            swap(arr[0],arr[size-1]);
            size--;
            heapify(arr,0,size);
        }
        return;
    }
    
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        int n=arr.size();
        //step1: creating a heap
        for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,i,n);
        }
        
        //sorting the heap
        heapSort(arr,n);
        //step2: compairing the rest
        // for(auto i:arr){
        //     cout<< i<< " ";
        // }
        // cout<<endl;
        vector<int> ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(arr[n-1]);
            n--;
        }
        
        return ans;
    }
};
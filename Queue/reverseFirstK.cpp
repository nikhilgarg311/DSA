//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        vector<int> ans;
        deque<int> dq;
        
        //process first window
        for(int i=0;i<k;i++){
            if(arr[i]<0){
                dq.push_back(i);
            }
        }
        
        //store ans
        if(!dq.empty()){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        //process for remaining windows
        for(int i=k;i<arr.size();i++){
            //removal from dq
            if(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }
            //addition
            if(arr[i]<0){
                dq.push_back(i);
            }
            //store ans
            if(!dq.empty()){
                ans.push_back(arr[dq.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
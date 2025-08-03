//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> ans;
        queue<int> temp;
        int n=q.size();
        int fh=n/2;
        
        for(int i=0;i<fh;i++){
            temp.push(q.front());
            q.pop();
        }
        
        while(!q.empty()){
            ans.push_back(temp.front());
            temp.pop();
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends
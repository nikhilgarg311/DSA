//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int people= mat.size();
        if(people==1){
            return 0;
        }
        //put all people in stack
        stack<int> s;
        for(int i=0;i<people;i++){
            s.push(i);
        }
        while(s.size()!=1){
            //pop top two
            int person1=s.top();
            s.pop();
            int person2=s.top();
            s.pop();
            
            if(mat[person1][person2]==1){
                //person1 know person2, so person1 cant be celebrity
                s.push(person2);
            }
            else if(mat[person2][person1]){
                s.push(person1);
            }
        }
        
        //now stack has only one element, need to confirm if its celebrity
        for(int i=0;i<people;i++){
            if(mat[s.top()][i]==1){
                return -1;
            }
            if(mat[i][s.top()]==0 && i!=s.top()){
                return -1;
            }
        }
        return s.top();
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
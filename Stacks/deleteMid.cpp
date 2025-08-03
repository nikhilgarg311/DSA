//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int size= s.size();
        int count=0;
        stack<int> s2;
        
        while(count<size/2){
            s2.push(s.top());
            s.pop();
            count++;
        }
        s.pop();
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
        // if(size&&1){
            
        // }
        // else{
        //     while(count< size/2)
        // }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        stack<int> s;
        int num;
        while (ss >> num) {
            s.push(num);
        }

        Solution ob;
        ob.deleteMid(s);
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
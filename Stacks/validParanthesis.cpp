//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        // code here
        stack<char> stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stk.push(s[i]);
            }
            else if(s[i]==')' || s[i]=='}' || s[i]==']'){
                if(stk.empty()){
                    return false;
                }
                char compare;
                if(stk.top()=='('){
                    compare=')';
                }
                if(stk.top()=='{'){
                    compare='}';
                }
                if(stk.top()=='['){
                    compare=']';
                }
                if(compare!=s[i]){
                    return false;
                }
                else{
                    stk.pop();
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
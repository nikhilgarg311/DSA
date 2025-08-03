//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                    st.push(s[i]);
                }
            else{
                if(s[i]==')'){
                    int isRedundant=1;
                    while(st.top()!='('){
                        if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'){
                            st.pop();
                            isRedundant=0;
                        }
                    }
                    st.pop();
                    if(isRedundant==1){
                        return 1;
                    }
                    
                }
            }
        }
        return 0;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends
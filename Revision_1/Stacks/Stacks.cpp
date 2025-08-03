#include<iostream>
#include<stack>
using namespace std;


void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void printStackReverse(stack<int> s){
    if(s.size()==0){
        return;
    }
    int top =s.top();
    s.pop();
    printStackReverse(s);
    cout<<top<<endl;
    s.push(top);
}


void insertElementAtBottomRecurssion(stack<int> &s,int n){
    if(s.size()==0){
        s.push(n);
        return;
    }
    int top= s.top();
    s.pop();
    insertElementAtBottomRecurssion(s,n);
    s.push(top);
}


void insertSorted(stack<int> &s,int element){
    if(s.size()==0||s.top()>=element){
        s.push(element);
        return;
    }
    int top= s.top();
    s.pop();
    insertSorted(s,element);
    s.push(top);
}

void sortStack(stack<int> &s){
    if(s.size()==0){
        return;
    }
    int element= s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,element);
}

void deleteMid(stack<int> &s,int originalSize){
    if(s.size()==0||s.size()==1){
        return;
    }
    if(s.size()==(originalSize/2)+1){
        s.pop();
        return;
    }
    int top=s.top();
    s.pop();
    deleteMid(s,originalSize);
    s.push(top);
}

int checkRedundancy(string s) {
    // code here
    stack<int> st;
    for(int i=0;i<s.length();i++){
        
        if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            int isRedundant=1;
            while(st.top()!='('){
                st.pop();
                isRedundant=0;
            }
            st.pop();
            if(isRedundant){
                return 1;
            }
            
        }
        else{
            continue;
        }
    }
    return 0;    
}

bool isBalanced(string& s) {
    // code here
    stack<int> st;
    for(int i=0;i<s.length();i++){
        
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty()){
                return false;
            }
            if(st.top()!='('){
                return false;
            }
            st.pop();
        }
        else if(s[i]=='}'){
            if(st.empty()){
                return false;
            }
            if(st.top()!='{'){
                return false;
            }
            st.pop();
        }
        else if(s[i]==']'){
            if(st.empty()){
                return false;
            }
            if(st.top()!='['){
                return false;
            }
            st.pop();
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}

vector<int> nextLargerElement(vector<int>& arr) {
    // code here
    int size= arr.size();
    stack<int> s;
    vector<int> ans;
    s.push(-1);
    for(int i=size-1;i>=0;i--){
        // compare s.top with curr
        // if curr>s.top store ans and push in stack
        // else pop till greater not found;
        int curr=arr[i];
        if(curr<s.top()){
            ans.push_back(s.top());
            s.push(curr);
        }
        else{
            // if(s.empty()){
            //     revAns.push_back(-1);
            // }
            //cout<<"Inside else"<<s.top()<<" "<<curr<<endl;
            while(s.size()!=1 && s.top()<=curr){
                //cout<<"entered while loop"<<endl;
                s.pop();
            }
            ans.push_back(s.top());
            s.push(curr);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans; 
    
}

int celebrity(vector<vector<int>> & mat) {
    int n = mat.size();
    stack<int> st;

    // Push everybody in stack
    for (int i = 0; i < n; i++)
        st.push(i);

    // Find a potential celebrity
    while (st.size() > 1) {

        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        // if a knows b
        if (mat[a][b]) {
            st.push(b);
        }
        else {
            st.push(a);
        }
    }

    // Potential candidate of celebrity
    int c = st.top();
    st.pop();

    // Check if c is actually
    // a celebrity or not
    for (int i = 0; i < n; i++) {
        if(i == c) continue;

        // If any person doesn't
        // know 'c' or 'c' doesn't
        // know any person, return -1
        if (mat[c][i]|| !mat[i][c])
            return -1;
    }

    return c;
}


vector<int> smallerPreviousIndex(vector<int> &arr){
        stack<int> s;
        vector<int> ans(arr.size());
        for(int i=0;i<arr.size();i++){
            if(!s.empty() && s.top()!=-1 && arr[i]>arr[s.top()]){
                ans[i]=(s.top());
            }
            else{
                if(s.empty()){
                    ans[i]=(-1);
                }
                else{
                    while(!s.empty() && s.top()!=-1 && arr[i]<=arr[s.top()]){
                        s.pop();
                    }
                    if(s.empty()){
                        ans[i]=(-1);
                    }
                    else{
                        ans[i]=(s.top());
                    }
                }
                
            }
            s.push(i);
        }
                //reverse(ans.begin(),ans.end());
        return ans;
        
    }
    
vector<int> smallerNextIndex(vector<int> &arr){
    stack<int> s;
    vector<int> ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        if(!s.empty() && s.top()!=-1 && arr[i]>arr[s.top()]){
            ans[i]=s.top();
        }
        else{
            if(s.empty()){
                ans[i]=(-1);
            }
            else{
                while(!s.empty() && s.top()!=-1 && arr[i]<=arr[s.top()]){
                    s.pop();
                }
                if(s.empty()){
                    ans[i]=(-1);
                }
                else{
                    ans[i]=(s.top());
                }
            }
            
        }
        s.push(i);
    }
    //reverse(ans.begin(),ans.end());
    return ans;
}

int getMaxArea(vector<int> &arr) {
    // Your code here
    vector<int> next;
    vector<int> prev;
    
    next=smallerNextIndex(arr);
    prev=smallerPreviousIndex(arr);
    
    int area=0;
    for(int i=0;i<arr.size();i++){

        if(next[i]==-1){
            next[i]=arr.size();
        }
        int newArea=arr[i]* (next[i]-prev[i]-1);
        area=max(area,newArea);
    }
    return area;
    
    
}

int main(){
    cout << "Hello Stacks" << endl; 
   stack<int> s;
   
   //----basic operations--------
   s.push(5);
   cout<< s.top();
   cout<<endl<< s.size();
   s.pop();
   cout<<endl<< s.size();
   cout<<endl<< s.empty();
   //-----------------------------
}
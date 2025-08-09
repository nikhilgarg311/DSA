// User function Template for C++
class Solution {
  public:

    bool inDict(string s, vector<string> &dict){
        for(int i=0;i<dict.size();i++){
            if(s==dict[i]){
                return true;
            }
        }
        return false;
        
    }
    void solve(vector<string> &dict, string& s, int start, vector<string>& ans, string currString, string final){
        if(start >=s.size()){
            //base case
            if(currString.length()==0){
                ans.push_back(final);
            }
            return;
        }
        
        currString.append(1,s[start]);
        
        if(inDict(currString,dict)){
            string tempFinal=final;
            tempFinal.append(currString);
            tempFinal.append(1,' ');
            string tempCurr="";
            //include call
            solve(dict,s,start+1,ans,tempCurr,tempFinal);
        }
        
        //exclude call
        solve(dict,s,start+1,ans,currString,final);
        return;
    }
  
    
    vector<string> wordBreak(vector<string>& dict, string& s) {
        // code here
        // unordered_map<string,int> m;
        // for(int i=0;i<dict.size();i++){
        //     m.insert({dict[i],i});
        // }
        
        vector<string> ans;
        solve(dict, s, 0, ans, "","");
        return ans;
        
        
    }
};
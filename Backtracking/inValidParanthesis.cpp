class Solution {
public:
    unordered_set<string> res;
    void solve(string &s, int index,int countOpen,int remLeft, int remRight, string path){
        //base case
        if(index>=s.size()){
            if(remLeft==0 && remRight==0 && countOpen==0){
                res.insert(path);
            }
            return;
        }

         // Remaining characters
        int remaining = s.size() - index;

        // Pruning: impossible cases
        if (remLeft < 0 || remRight < 0 || countOpen < 0) return;
        if (remLeft > remaining || remRight > remaining) return;

        
        if(s[index]=='('){
            //exclude from path
            if(remLeft>0){
                solve(s,index+1,countOpen,remLeft-1,remRight,path);
            }

            //include in path
            string temp=path;
            temp.append(1,s[index]);
            solve(s,index+1,countOpen+1,remLeft,remRight,temp);
        }
        else if(s[index]==')'){

           //exclude from path
            if(remRight>0){
                solve(s,index+1,countOpen,remLeft,remRight-1,path);
            }

           //include in path
            string temp=path;
            temp.append(1,s[index]);
            if(countOpen>0){
                solve(s,index+1,countOpen-1,remLeft,remRight,temp);
            }            

        }
        else{
            solve(s,index+1,countOpen,remLeft,remRight,path+s[index]);
        }

    }



    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int remLeft=0,remRight=0;
        for(char i:s){
            if(i=='('){
                remLeft++;
            }
            if(i==')'){
                if(remLeft>0){
                    remLeft--;
                }
                else{
                    remRight++;
                }
            }
        }

        solve(s,0,0,remLeft,remRight,"");
        return vector<string>(res.begin(),res.end());
    }
};
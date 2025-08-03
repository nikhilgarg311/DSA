//Find All Anagrams in a String
//Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> arr(26,0);
        vector<int> ans;
        if(p.length()>s.length()){
            return ans;
        }
        for(int i=0;i<p.length();i++){
            int index= p[i]- 'a';
            arr[index]++;
        }

        vector<int> count(26,0);
        //first window
        for(int j=0;j<p.length();j++){
                int index= s[j]- 'a';
                count[index]++;
        }
        bool flag=true;
        for(int i=0;i<26;i++){
            if(arr[i]!=count[i]){
                flag=false;
                break;
            }    
        }
        if(flag){
            ans.push_back(0);
        }


        //sliding window
        for(int i=p.length();i<s.length();i++){
            int index= s[i]- 'a';
            int prevIndex= s[i-p.length()] - 'a';
            count[index]++;
            count[prevIndex]--;

            bool flag=true;
            for(int k=0;k<26;k++){
                if(arr[k]!=count[k]){
                    flag=false;
                    break;
                }    
            }
            if(flag){
                ans.push_back(i-p.length()+1);
            }
        }
    return ans;
    }
};
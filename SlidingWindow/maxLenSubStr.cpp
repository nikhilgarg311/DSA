class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0){
            return 0;
        }
        vector<int> arr(128,0);
        int start=0;
        int end=0;
        arr[s[start]]++;
        int maxi=1;
        for(int i=1;i<s.length();i++){
            int index=s[i];
            if(arr[index]!=0){
                //char repeated drop one and add one
                while(s[start]!=s[i]){
                    arr[s[start]]--;
                    start++;
                }
                if(start>=end){
                    end++;
                    start=end;
                }
                else{
                    end++;
                    start++;
                }
            }
            else{
                arr[index]++;
                end++;
                maxi=max(maxi,end-start+1);
            }
            //debugging
            // for(int k=start;k<=end;k++){
            //     cout<<s[k];
            // }
            // cout<<endl;
        }
        return maxi;
    }
};
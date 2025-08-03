#include<iostream>
#include<string>
#include<vector>
using namespace std;

void subSequences(string &str,string output,int index,vector<string>&ans){
//base case
if(index>str.length()-1){
    if(output.length()>0){
        ans.push_back(output);
    }
    return;
}

//exclude call
subSequences(str,output,index+1,ans);

//include call
output.push_back(str[index]);
subSequences(str,output,index+1,ans);

}

int main(){
    string str = "abc";
    vector<string> ans;
    string output= "";
    int index=0;

    subSequences(str,output,index,ans);

    for(string i:ans){
        cout<<i<<" ";
    }

}
#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string s, int i,int j){
    cout<<s<<" "<<i<<" "<<j<<endl;
//base case
if(i>j){
    return true;
}
if(s[i]!=s[j]){
    return false;
}
else{
    i++;j--;
    return checkPalindrome(s,i,j);
}
}
int main(){
    string s= "noon";
    cout<<checkPalindrome(s,0,s.length()-1);
}
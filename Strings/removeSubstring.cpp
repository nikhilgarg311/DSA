#include<iostream>
#include<string>
using namespace std;

void removeSubstring(string str,string subStr){
    while(str.length()!=0 && str.find(subStr)<str.length()){
        str.erase(str.find(subStr),subStr.length());
    }
    cout<<str<<endl;
}
int main(){
     string str="daabcbaabcbc";
     string subStr="abc";
     removeSubstring(str,subStr);
}
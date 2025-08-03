#include<iostream>
#include<vector>
using namespace std;

int compress(vector<char> str){
int i=0,ans=0,count=0;
while(i<str.size()){
    int j=i+1;
    while(j<str.size() && str[i]==str[j]){
        j++;
    }
    count=j-i;
    str[ans]=str[i];
    ans++;
    if(count>1){
        string s=to_string(count);
        for(char ch:s){
            str[ans]=ch;
            ans++;
        }
    }
    i=j;
}
return ans;
}

int main(){
    //case1
    vector<char> str1;
    str1.push_back('a');
    str1.push_back('a');
    //case 2
    vector<char> str2;
    str2.push_back('a');
    str2.push_back('a');
    str2.push_back('b');
    str2.push_back('b');
    str2.push_back('c');
    str2.push_back('c');
    str2.push_back('c');
    //case 3
    vector<char> str3;
    str3.push_back('a');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    str3.push_back('b');
    //case 4
    vector<char> str4;
    str4.push_back('a');
    str4.push_back('a');
    str4.push_back('a');
    str4.push_back('a');
    str4.push_back('a');
    str4.push_back('b');


cout<<"Length of new 1st array: "<<compress(str1)<<endl;
cout<<"Length of new 2nd array: "<<compress(str2)<<endl;
cout<<"Length of new 3rd array: "<<compress(str3)<<endl;
cout<<"Length of new 4th array: "<<compress(str4)<<endl;
}
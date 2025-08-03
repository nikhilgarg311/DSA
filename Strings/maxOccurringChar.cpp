#include<iostream>
#include<string>
#include<vector>
using namespace std;

char getMaxOccChar(string s){
vector<int> arr(26,0);
int number=0;
for(int i=0;i<s.length();i++){
    if(s[i]>='a'&&s[i]<='z'){
        number=s[i]-'a';
    }
    else{
        number=s[i]-'A';
    }
    arr[number]++;
}
int max=-1, index;
for(int j=0;j<arr.size();j++){
    if(max<arr[j]){
        max=arr[j];
        index=j;
    }
}
char ch='a'+index;
return ch;
}

int main(){
    string s="output";
    cout<<"Max occuring char is: "<<getMaxOccChar(s)<<endl;
}
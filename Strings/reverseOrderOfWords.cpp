#include<iostream>
#include<string>
using namespace std;

void reverseOrder(string s){
int n=s.length()-1;
int temp;
string newString;
while(n>=0){
    while(s[n]!=' ' && n>=0){
        n--;
    }
    temp=n+1;
    while(s[temp]!=' ' && temp<s.length()){
        newString.push_back(s[temp]);
        temp++;
    }
    newString.push_back(s[n]);
    n--;
}

cout<<"String after reversing the order of words is: "<<newString<<endl;
}

int main(){
    string s="The sky is blue";
    reverseOrder(s);
}
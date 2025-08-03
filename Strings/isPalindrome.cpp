#include<iostream>
#include<string>
using namespace std;

char toLowercase(char ch){
    if(ch>='A'&& ch<='Z'){
        return ch + 'a' - 'A';
    }
    else{
        return ch;
    }
}

bool checkPalindrome(string s){ // not case sensitive
int start=0;
int end=s.length()-1;
while(start<=end){
    if(toLowercase(s[start])!=toLowercase(s[end])){
        return 0;
    }
    else{
        start++;
        end--;
    }
}
return 1;
}

void isPalindrome(string s){
// firstly we will put all non alpha-numeric characters to the right
int j=0;
string temp;
while(j<s.length()){
    if(toLowercase(s[j])>='a' && toLowercase(s[j])<='z'){
        temp.push_back(s[j]);
    }
    else if(s[j]>='0' && s[j]<='9'){
        temp.push_back(s[j]);
    }
j++;
}
cout<<"string is: "<<temp<<endl;
//put null character after all valid characters
cout<<"Is it palindrome: "<<checkPalindrome(temp)<<endl;;
}

int main(){
    string s="No)12#-32@1on";
    isPalindrome(s);
}
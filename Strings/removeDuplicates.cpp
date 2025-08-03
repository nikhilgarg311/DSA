#include<iostream>
#include<string>
using namespace std;

void removeDuplicates(string s) {
        int i=0,count=0;
        while(i<s.length()-1 && s.length()!=0){
            count=1;
            while(s[i]==s[i+1]){
                count++;
                i++;
            }
            if(count>1){
                s.erase(i+1-count,count);
                i=0;
            }
            else{
                i++;
            }
        }
        cout<< s;
    }
int main(){
    string s = "aaaaaa";
    removeDuplicates(s);
}
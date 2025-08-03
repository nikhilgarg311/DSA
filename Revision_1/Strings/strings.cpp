/* Online C++ Compiler and Editor */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char maxOccurringChar(string s){
    
    int arr[26]={0};
    
    for(int i=0;i<s.length();i++){
        int ch= s[i]-'a';
        arr[ch]++;
    }
    
    int max=-1,index;
    for(int i=0;i<26;i++){
        if(arr[i]>max){
            max=arr[i];
            index=i;
        }
    }
    char ch= index+'a';
    return ch;
    
}



int main()
{
    string s= "not";
    cout<<maxOccurringChar(s)<<endl;
   return 0;
}
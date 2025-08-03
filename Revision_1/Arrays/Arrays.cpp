/* Online C++ Compiler and Editor */
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void sumOfTwoArrays(int a[],int b[],int n,int m){
    
    vector<int> ans;
    int carry=0;
    int sum=0;
    while(m>0){
        sum=a[m-1]+b[n-1]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        m--;n--;
    }
    
    while(n>0){
        sum=a[n-m-1]+carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);
        n--;
    }
    
    reverse(ans.begin(),ans.end());
    
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
}


int main()
{
    
    int a[] = { 1, 2, 3 };
    int b[] = { 2, 1, 4 };
    cout << "Hello World" << endl; 
    int carry=0;
    vector<int> ans;
    int n=sizeof(a)/sizeof(a[0]);
    int m=sizeof(b)/sizeof(b[0]);
    
    if(n>=m){
        sumOfTwoArrays(a,b,n,m);
    }
    else{
        sumOfTwoArrays(b,a,m,n);
    }
   return 0;
}
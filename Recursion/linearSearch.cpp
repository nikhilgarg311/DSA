#include<iostream>
#include<array>
using namespace std;

bool search(int arr[],int n,int size){
//base case
if(size==0){
    return false;
}

if(arr[0]==n){
    return true;
}
else{
    return search(arr+1,n,size-1);
}


//recursion
}

int main(){
    int arr[6]={10,20,5,23,67,90};
    cout<<search(arr,5,6)<<endl;
}

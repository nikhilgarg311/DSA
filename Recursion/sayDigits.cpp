#include<iostream>
#include<string>
#include<array>
using namespace std;

void sayDigits(string arr[],int num){

    //base case
    if(num/10==0){
        cout<<arr[num]<<" ";
        return;
    }
    else{
        sayDigits(arr,num/10);
        cout<<arr[num%10]<<" ";
    }

}
int main(){
    int n=410;
    string arr[10]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    sayDigits(arr,n);
}
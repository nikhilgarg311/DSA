#include<iostream>
#include<array>
using namespace std;

int sum(int arr[],int size){
    //base condition
    if (size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    else{
        return arr[0]+ sum(arr+1,size-1);
        //sum=arr[0]+remaining array

    }
}
int main(){
    int arr[5]={3,2,5,1,6};
    cout<<"Sum= "<<sum(arr,5);
}
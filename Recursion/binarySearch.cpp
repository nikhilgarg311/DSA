#include<iostream>
#include<array>
using namespace std;

bool binarySearch(int arr[],int size, int n){
    //base case
    if(size==0){
        return false;
    }
    int mid=size/2;
    if(arr[mid]==n){
        return true;
    }
    else if(arr[mid]<n){
        return binarySearch(arr+mid+1,size-mid,n);
    }
    else if(arr[mid]>n){
        return binarySearch(arr,size-mid-1,n);
    }

}
int main(){
    int arr[6]={10,20,23,67,69,90};
    cout<<binarySearch(arr,6,90)<<endl;
}
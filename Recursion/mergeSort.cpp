#include<iostream>
#include<array>
using namespace std;


void merge(int *arr,int s,int e){  //without using any extra array
    int mid=s +(e-s)/2;
    
    int indexLeft=s;
    int indexRight=mid+1;
    cout<<"left array"<<endl;
    for(int i=s;i<=mid;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"right array"<<endl;
    for(int i=mid+1;i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    //merge 2 sorted arrays
    while (indexLeft<=mid && indexRight<=e){
        if(arr[indexRight]<arr[indexLeft]){
            int value=arr[indexRight];
            for(int temp=indexRight;temp>indexLeft;temp--){
                arr[temp]=arr[temp-1];
            }
            arr[indexLeft]=value;
            indexRight++;
            mid++;
            indexLeft++;
        }
        else{
            indexLeft++;
        }
    }  
    for(int i=0;i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void breakArray(int *arr,int s,int e){
    //base case
    if(s>=e){
        return;
    }
    int mid= s + (e-s)/2;
    //break left part
    breakArray(arr,s,mid);

    //break right part
    breakArray(arr,mid+1,e);

    //merge
    merge(arr,s,e);
}

int main(){

int arr[12]={2,5,1,6,9,11,0,1,3,6,8,7};
    breakArray(arr,0,11);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}

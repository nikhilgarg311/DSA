#include<iostream>
#include<array>
using namespace std;

int partition(int *arr, int s, int e){
    int count=0;
    int pivot=arr[s];

    //counting smaller elements
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }

    //putting the first element at right place
    swap(arr[s],arr[s+count]);
    int i=s,j=e;
    while(i<= s+count && j>=s+count){
        if(arr[i]<=pivot){
            i++;
        }
        if(arr[j]>=pivot){
            j--;
        }
        if(arr[i]>pivot && arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }

    for(int i=s;i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return (s+count);
}

void quickSort(int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    cout<<"ji"<<endl;
    //partioning the array
    int p=partition(arr,s,e);

    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int main(){
    int arr[12]={2,5,1,6,9,11,0,1,3,6,8,7};
    quickSort(arr,0,11);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}
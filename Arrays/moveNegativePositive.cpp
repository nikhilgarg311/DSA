
#include<iostream>
using namespace std;

vector<int> move(vector<int> &arr){

    int size=arr.size();
    int p=0, n=size-1;

    while(arr[p]<0 && p<size-1){
        p++;
    }
    while(arr[n]>0 && n>0){
        n--;
    }
    if(p==size-1||n==1){
        return;
    }
    else{
        while(p<n){
            swap(arr[p],arr[n]);
            p++,n--;

            while(arr[p]<0 && p<size-1){
                p++;
            }
            while(arr[n]>0 && n>0){
                n--;
            }
        }
    }
    return arr;

}

int main() {
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    vector<int> ans = move(arr);
    
    for (auto num: ans) {
        cout << num << " ";
    }
    cout<<endl;

    return 0;
}
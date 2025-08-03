#include<iostream>
#include<vector>
using namespace std;

void sum(vector<int> arr1 , vector<int> arr2){
vector<int> arr3;
int carry=0,i=arr1.size()-1,j=arr2.size()-1,sum=0;

while(j>=0 && i>=0){
sum=arr1[i]+arr2[j]+carry;
carry=sum/10;
sum=sum%10;
arr3.push_back(sum);
i--;
j--;
}

while(i>=0){
    sum=arr1[i]+carry;
    carry=sum/10;
    sum=sum%10;
    arr3.push_back(sum);
    i--;
}
while(j>=0){
    sum=arr2[j]+carry;
    carry=sum/10;
    sum=sum%10;
    arr3.push_back(sum);
    j--;
}
if(carry!=0){
    sum=carry;
    carry=sum/10;
    sum=sum%10;
    arr3.push_back(sum);
}

//reversing the arr

int start=0, end=arr3.size()-1;
while(start<=end){
    swap(arr3[start],arr3[end]);
    start++;end--;
}

for(int i:arr3){
    cout<<i<<" ";
}cout<<endl;

}

int main(){
vector<int> arr1,arr2;

arr1.push_back(9);
arr1.push_back(9);
arr1.push_back(9);
arr1.push_back(9);
arr1.push_back(9);
arr2.push_back(1);
arr2.push_back(2);
arr2.push_back(3);
arr2.push_back(4);
arr2.push_back(5);
sum(arr1,arr2);
}
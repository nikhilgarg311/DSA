#include<iostream>
#include<vector>
using namespace std;

void findSubsets(vector<int> &nums,vector<int> output,int index,vector< vector<int> >&ans){
    //base case
    if(index>nums.size()-1){
        ans.push_back(output);
        return;
    }

    //exclusion call
    findSubsets(nums,output,index+1,ans);

    //inclusion call
    output.push_back(nums[index]);
    findSubsets(nums,output,index+1,ans);
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<int> output;
    vector<vector<int> > ans;
    int index=0;

    findSubsets(nums,output,index,ans);

    for(vector<int> i:ans){
        cout<<"[";
        for(int j:i){
            cout<<j<<",";
        }cout<<"] ";
    }cout<<endl;
}
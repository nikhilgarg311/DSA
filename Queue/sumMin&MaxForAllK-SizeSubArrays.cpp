#include <bits/stdc++.h>
using namespace std;

int subArrSum(int nums[], int len, int K) {
    deque<int> maxi;
    deque<int> mini;
    //process first window
    for(int i=0;i<K;i++){
        
        //pop all from maxi which are smaller
        while(!maxi.empty()&& nums[maxi.back()]<=nums[i]){
            maxi.pop_back();
        }
        
        //pop all from min which are greater
        while(!mini.empty() && nums[mini.back()]>=nums[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        
    }
    int sum=nums[maxi.front()]+nums[mini.front()];
    //process remaining windows
    for(int i=K;i<len;i++){
        
        //removal
        while(!maxi.empty() && i-maxi.front()>K){
            maxi.pop_front();
        }
        while(!mini.empty() && i-mini.front()>K){
            mini.pop_front();
        }
        
        //addition
        //pop all from maxi which are smaller
        while(!maxi.empty()&& nums[maxi.back()]<=nums[i]){
            maxi.pop_back();
        }
        
        //pop all from min which are greater
        while(!mini.empty() && nums[mini.back()]>=nums[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        sum=sum+nums[maxi.front()]+nums[mini.front()];
    }
    return sum;
}
int main() {
    int nums[] = {2, 5, -1, 7, -3, -1, -2};
    int len = sizeof(nums) / sizeof(nums[0]);
    int K = 4;
    cout << "The ans of minimum and maximum elements of all subarrays of size K is " << subArrSum(nums, len, K);
    return 0;
}
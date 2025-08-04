#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Stores indices
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements outside the window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove all elements smaller than the current element from the back
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add current element index to deque
        dq.push_back(i);

        // The front of the deque is the largest element in the window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

// Example usage
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> res = maxSlidingWindow(nums, k);

    for (int val : res) {
        cout << val << " ";
    }

    return 0;
}

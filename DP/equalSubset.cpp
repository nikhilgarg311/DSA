class Solution {
public:
    bool solve(int i, int currentSum, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base cases
        if (currentSum == target) return true;
        if (i >= arr.size() || currentSum > target) return false;

        if (dp[i][currentSum] != -1) return dp[i][currentSum];

        // Include current element
        bool include = solve(i + 1, currentSum + arr[i], target, arr, dp);
        // Exclude current element
        bool exclude = solve(i + 1, currentSum, target, arr, dp);

        return dp[i][currentSum] = (include || exclude);
    }

    bool equalPartition(vector<int>& arr) {
        int totalSum = 0;
        for (int x : arr) totalSum += x;

        // If sum is odd, can't partition equally
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

        return solve(0, 0, target, arr, dp);
    }
};
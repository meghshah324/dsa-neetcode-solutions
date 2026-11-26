class Solution {
public:
    bool isPossible(int ind, int tSum,vector<int>& nums, vector<vector<int>>&dp){
        if(ind >= nums.size()){
            return tSum == 0;
        }
        if(dp[ind][tSum] != -1) return dp[ind][tSum];
        int notTake = isPossible(ind + 1, tSum, nums, dp);
        int take = false;
        if(tSum >= nums[ind]){
            take = isPossible(ind + 1, tSum - nums[ind], nums, dp);
        }
        return dp[ind][tSum] = take | notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % 2 != 0) return false;
        int targetSum = totalSum/ 2;
        vector<vector<int>>dp(n, vector<int>(targetSum + 1, -1));
        return isPossible(0, targetSum, nums, dp);
    }
};

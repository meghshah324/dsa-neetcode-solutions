class Solution {
public:
    int climbStairHelper(int step, vector<int>&dp){
        if(step == 1) return 1;
        if(step == 2) return 2;
        if(dp[step] != -1) return dp[step];
        return dp[step] = climbStairHelper(step - 1, dp) + climbStairHelper(step - 2, dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n + 1, -1);
        return climbStairHelper(n, dp);
    }
};

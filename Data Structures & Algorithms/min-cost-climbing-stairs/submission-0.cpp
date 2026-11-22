class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int noOfStep = cost.size();
        vector<int>dp(noOfStep + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i <= noOfStep; i++){
            if(i <  noOfStep) dp[i] += cost[i];
            dp[i] += min(dp[i - 1], dp[i - 2]);
        }
        return dp[noOfStep];
    }
};

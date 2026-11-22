class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int noOfStep = cost.size();
        vector<int>dp(noOfStep + 1, 0);
        int step1 = cost[0];
        int step2 = cost[1];
        int step3 = 0;
        for(int i = 2; i <= noOfStep; i++){
            step3 = 0;
            if(i <  noOfStep) step3 += cost[i];
            step3 += min(step1, step2);
            step1 = step2;
            step2 = step3;
        }
        return step3;
    }
};

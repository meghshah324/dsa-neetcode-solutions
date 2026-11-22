class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int noOfStep = cost.size();
        int step1 = cost[0];
        int step2 = cost[1];
        for(int i = 2; i <= noOfStep; i++){
            int currCost = 0;
            if(i <  noOfStep) currCost += cost[i];
            currCost += min(step1, step2);
            step1 = step2;
            step2 = currCost;
        }
        return step2;
    }
};

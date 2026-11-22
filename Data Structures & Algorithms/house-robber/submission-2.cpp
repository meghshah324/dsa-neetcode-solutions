class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int rob1 = nums[0];
        if(n == 1) return rob1;
        int rob2 = 0;
        if(n >= 2) rob2= max(nums[0], nums[1]);
        for(int  i = 2; i < n; i++){
            int temp = max(rob2, nums[i] + rob1);
            rob1 =  rob2;
            rob2 = temp;
        }
        return rob2;
    }
};

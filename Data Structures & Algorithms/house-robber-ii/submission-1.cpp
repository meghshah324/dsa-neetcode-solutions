class Solution {
public:
    int findMax(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        vector<int>temp1, temp2;
        if(nums.size() == 1) return nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                temp1.push_back(nums[i]);
            }else if(i == nums.size() - 1){
                temp2.push_back(nums[i]);
            }else{
                temp1.push_back(nums[i]);
                temp2.push_back(nums[i]);
            }
        }
        return max(findMax(temp1), findMax(temp2));
    }
};

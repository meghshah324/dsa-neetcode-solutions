class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>s;
        for(int i = 0 ; i < nums.size(); i++){
            int rem = target - nums[i];
            if(s.find(rem) != s.end()){
                return {s[rem] , i};
            }
            if(s.find(nums[i]) == s.end()){
                 s[nums[i]] = i;
            }
        }
        return {};
    }
};

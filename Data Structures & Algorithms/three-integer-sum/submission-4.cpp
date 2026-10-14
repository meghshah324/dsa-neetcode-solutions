class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            while (i > 0 && i < nums.size() - 2 && nums[i] == nums[i - 1]) {
                i++;
            }
            int first = nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int currSum = first + nums[l] + nums[r];
                if (currSum == 0) {
                    ans.push_back({first, nums[l], nums[r]});
                    cout << currSum << endl;
                    l++;
                    while (l > 0 && l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                    r--;
                } else if (currSum > 0) {
                    r--;
                } else {
                    l++;
                    while (l > 0 && l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};

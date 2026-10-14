class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>>temp;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int first = nums[i];
            int l = i + 1 , r = nums.size() - 1;
            while(l < r){
                int currSum = first + nums[l] + nums[r];
                if(currSum == 0){
                    temp.insert({first , nums[l], nums[r]});
                    l++;
                    r--;
                }else if(currSum > 0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        for(auto x : temp){
            ans.push_back(x);
        }
        return ans;
    }
};


//0 0 0 0 0

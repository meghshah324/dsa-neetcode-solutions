class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        int noArr = 0, totalSum = 0;
        mp[0] = 1;
        for(int i = 0 ;  i < nums.size(); i++){
            totalSum += nums[i];
            if(mp.find(totalSum - k) != mp.end()){
                noArr += mp[totalSum - k];
            }
            mp[totalSum]++;
        }
        return noArr;
    }
};
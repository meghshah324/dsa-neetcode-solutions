class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<vector<int>>vp(n + 1);
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto it: mp){
            int frq = it.second;
            int ele = it.first;
            vp[frq].push_back(ele);
        }
        vector<int>res;
        for(int i = vp.size()- 1; i >= 0; i--){
             for(int j = 0 ; j < vp[i].size(); j++){
                 res.push_back(vp[i][j]);
                 if(res.size() == k){
                     return res;
                 }
             }
        }
        return res;
    }
};

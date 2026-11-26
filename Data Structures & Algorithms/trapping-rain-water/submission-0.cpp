class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pref(n, 0), suff(n, 0);
        pref[0] = height[0];
        suff[n - 1] = height[n - 1];
        for(int i = 1 ; i < height.size(); i++){
             pref[i] = max(pref[i - 1], height[i]);
        }
        for(int i = n - 2 ; i >= 0; i--){
             suff[i] = max(suff[i + 1], height[i]);
        }
        int trapWater = 0;
        for(int i = 1 ; i < height.size() - 1; i++){
            int minWall = min(pref[i - 1], suff[i + 1]);
            trapWater += max(minWall - height[i], 0);
        }
        return trapWater;     
    }
};

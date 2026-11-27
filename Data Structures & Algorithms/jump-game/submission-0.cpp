class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool>track(n, false);
        track[0] = true;
        for(int i = 0 ; i < n; i++){
            if(track[i] == true){
                for(int j = 1; j <= nums[i]; j++){
                    if(i + j < n) track[i + j] = true;
                }
            }
        }
        return track[n - 1];
    }
};

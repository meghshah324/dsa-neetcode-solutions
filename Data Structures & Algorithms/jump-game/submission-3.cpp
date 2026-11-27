class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> track(n + 1, 0);
        track[0] = 1;

        if (n > 1) track[1] = -1;

        for (int i = 0; i < n; i++) {
            if(i > 0) track[i] += track[i - 1];
            if (nums[i] > 0 && track[i] > 0) {

                if (i + 1 < n)
                    track[i + 1] += 1;

                int steps = min(nums[i] + i + 1, n);
                track[steps] -= 1;
            }
        }
        return track[n - 1] > 0;
    }
};
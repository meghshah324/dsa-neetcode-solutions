class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            if (i - j + 1 > k) {
                while (!pq.empty() && pq.top().second <= (i - k)) {
                    pq.pop();
                }
                j++;
            }
            if (i - j + 1 == k) {
                ans.push_back(pq.top().first);
            }
        }
        return ans;
    }
};

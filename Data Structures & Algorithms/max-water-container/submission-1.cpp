class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<pair<int,int>>vp;
        set<int>s;
        int ans = 0;
        for(int i = 0 ; i < heights.size(); i++){
            vp.push_back({heights[i], i});
            s.insert(i);
        }
        sort(vp.begin(),vp.end());
        for(int i = 0 ; i < vp.size() - 1; i++){
            int ind = vp[i].second;
            int val = vp[i].first;
            s.erase(ind);
            int minInd = *s.begin();
            int maxInd = *s.rbegin();
            ans = max(ans, val * max(abs(minInd - ind), abs(maxInd - ind)));
        }
        return ans;        
    }
};

// 8 6 4 12 8


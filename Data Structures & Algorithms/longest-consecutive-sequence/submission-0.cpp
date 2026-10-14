class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_map<int,int>track;
        int maxLen = 0;
        for(int i = 0 ; i < nums.size(); i++){
             int val = nums[i];
             track[val] = 1;
        }
        for(auto it : track ){
            int val = it.first;
            int currVal = val;
            if(track[val] == 0)  continue;
            track[val] = 0;
            int currLen = 1;
            while(!track.empty()  && track.find(currVal - 1) != track.end()){
                currVal -= 1;
                track[currVal] = 0;
                currLen += 1;
            }
            currVal = val;
            while(!track.empty()  &&  track.find(currVal +1) != track.end()){
                currVal += 1;
                track[currVal] = 0;
                currLen += 1;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};


// 1
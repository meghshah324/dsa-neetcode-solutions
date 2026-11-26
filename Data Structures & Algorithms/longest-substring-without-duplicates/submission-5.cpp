class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int j = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            while (j < i && mp.find(s[i]) != mp.end()) {
                mp[s[j]] -= 1;
                if (mp[s[j]] == 0) mp.erase(s[j]);
                j++;
            }
            mp[s[i]]+=1;
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};

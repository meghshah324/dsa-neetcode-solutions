class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        map<char,int>mp;
        int i = 0;
        int ans = 0, maxC = 0;
        for(int j = 0 ; j < s.size(); j++){
            mp[s[j]]++;
            maxC = max(maxC, mp[s[j]]);
            while(i <= j && (j - i + 1) - maxC > k){
                mp[s[i]]-=1;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            ans = max(j - i + 1, ans);
        }
        return ans;
    }
};
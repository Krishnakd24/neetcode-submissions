class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0;
        int l=0;
        int to_change;
        int mf=0;
        int ans=0;      
        vector<int>mp(26,0);
        for(;r<s.size();r++){
            mp[s[r]-'A']++;
            mf=max(mf,mp[s[r]-'A']);
            to_change=r-l+1-mf;
            if(to_change>k){
                mp[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

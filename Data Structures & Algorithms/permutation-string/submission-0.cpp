class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>mp(26,0);
        for(char c:s1){
            mp[c-'a']++;
        }
        vector<int>have(26,0);
        int n=s1.size();
        if(n>s2.size()) return false;
        int l=0;
        for(char c:s2){
            if(mp[c-'a']>have[c-'a']){
                have[c-'a']++;
                n--;
                if(n==0)return true;
            }   
            else{
                while (l < s2.size() && (mp[c - 'a'] <= have[c - 'a'])) {
        have[s2[l] - 'a']--;
        // If the character removed was part of s1, we need to increment n
        if (have[s2[l] - 'a'] < mp[s2[l] - 'a']) {
            n++;
        }
        l++;
    }
                have[c-'a']++;
                n--;
                if(n==0)return true;

            }
        }
        return false;
    }
};

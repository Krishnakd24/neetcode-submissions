class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>feq;
        int ans=0;
        int left=0;
        int right=0;
        while(right<s.length()){
            while(feq[s[right]]!=0){
                feq[s[left]]--;
                left++;
            }
            feq[s[right]]++;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};

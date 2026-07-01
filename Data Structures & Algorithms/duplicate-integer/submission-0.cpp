class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums){
            if(mp.find(i)!=mp.end()) return 1;
            mp[i]++;
        }
        return 0;
    }
};
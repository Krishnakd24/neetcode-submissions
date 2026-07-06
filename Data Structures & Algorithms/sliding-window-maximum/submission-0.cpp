class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>maxf;
        int r=0;
    
        vector<int>ans;
        for(;r<nums.size();r++){
            maxf.push({nums[r],r});
            if(r>=k-1){
                while(maxf.top().second<r-k+1)maxf.pop();
                ans.push_back(maxf.top().first);
            }
        }
        return ans;
    }
};

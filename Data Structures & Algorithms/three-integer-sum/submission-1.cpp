class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int target=-nums[i];
            int right=nums.size()-1;
            int left=i+1;
            while(right>left){
                if(nums[right]+nums[left]==target){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
                else if(nums[right]+nums[left]<target) left++;
                else right --;
            }
        }
        return ans;
    }
};

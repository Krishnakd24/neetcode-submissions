class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>left_prod;
        vector<int>right_prod(nums.size(),0);
        int curr=1;
        for(int i=0;i<nums.size();i++){
            left_prod.push_back(curr);
            curr*=nums[i];
        }
        curr=1;
        for(int j=nums.size()-1;j>=0;j--){
            right_prod[j]=curr;
            curr*=nums[j];
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(left_prod[i]*right_prod[i]);
        }
        return ans;
    }
};

class Solution {
public:
int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    
    while (l < r) {
        int mid = l + (r - l) / 2;
        
        if (nums[mid] > nums[r]) {
            // The minimum is in the right half
            l = mid + 1;
        } else {
            // The minimum is in the left half (including mid)
            r = mid;
        }
    }
    return nums[l];
}
};

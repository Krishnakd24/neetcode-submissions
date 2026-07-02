class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=0;
        int r=heights.size()-1;
        int l=0;

        while(l<r){
            ans=max (ans,(r-l)*min(heights[r],heights[l]));
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return ans;
    }
};

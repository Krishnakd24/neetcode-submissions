class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        vector<int>next_s(n);
        vector<int>prev_s(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) prev_s[i]=-1;
            else prev_s[i]=st.top();

            st.push(i);
        }
        st={};
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) next_s[i]=n;
            else next_s[i]=st.top();

            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(next_s[i]-prev_s[i]-1));
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=0;
        int curr_mi=INT_MAX;
        for(int i:prices){
            if(curr_mi>i)curr_mi=i;
            prof=max(prof,i-curr_mi);
        }
        return prof;
    }
};

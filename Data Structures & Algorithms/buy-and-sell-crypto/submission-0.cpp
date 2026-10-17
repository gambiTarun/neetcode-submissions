class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int minv = prices[0];
        for(int i=1; i<prices.size(); i++){
            maxp = max(maxp, prices[i]-minv);
            minv = min(minv, prices[i]);
        }
        return maxp;
    }
};

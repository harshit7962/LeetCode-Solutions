class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0], res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<mn) mn=prices[i];
            res = max(res, prices[i]-mn);
        }
        
        return res;
    }
};
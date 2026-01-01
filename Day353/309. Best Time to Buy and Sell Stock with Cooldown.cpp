class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        
        int prevBuy = -prices[0], prevSell = 0, prevRest = 0;
        
        for (int i = 1; i < n; i++) {
            int buy = max(prevBuy, prevRest - prices[i]);
            int sell = prevBuy + prices[i];
            int rest = max(prevRest, prevSell);
            
            prevBuy = buy;
            prevRest = rest;
            prevSell = sell;
        }
        
        return max(prevSell, prevRest);
    }
};
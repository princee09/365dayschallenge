class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MAX, firstSell = 0;
        int secondBuy = INT_MAX, secondSell = 0;
        for (int price : prices) {
            firstBuy = min(firstBuy, price);
            firstSell = max(firstSell, price - firstBuy);
            secondBuy = min(secondBuy, price - firstSell);
            secondSell = max(secondSell, price - secondBuy);
        }
        
        return secondSell;
    }
};
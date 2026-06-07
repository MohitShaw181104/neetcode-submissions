class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprofit= INT_MAX;
        int maxprofit= 0;

        for(int price: prices){
            minprofit= min(minprofit,price);
            maxprofit= max(maxprofit, price- minprofit);
        }
        return maxprofit;
    }
};

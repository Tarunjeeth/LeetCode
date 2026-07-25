class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int profit=0;
        int n=prices.size();
        for (int i=0;i<n;i++){
            if (min>prices[i]){
                min=prices[i];
            }else{
                if (profit<prices[i]-min){
                    profit=prices[i]-min;
                }
            }
        }
        return profit;
    }
};
class Solution {
public:
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> hold(n), notHold(n);

    hold[0] = -prices[0];
    notHold[0] = 0;

    for (int i = 1; i < n; i++) {
        hold[i] = max(hold[i-1], notHold[i-1] - prices[i]);
        notHold[i] = max(notHold[i-1], hold[i-1] + prices[i]);
    }

    return notHold[n-1];
}
};
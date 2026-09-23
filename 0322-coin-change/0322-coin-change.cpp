// time complexity of this approach will be O(amount*n) where n=coins.size() and sapce will be O(amount) as we are creating a extra vector here .The main idea here is that when you taking a let's say 3 to make 6 then how much coins will be needed to make amount 6-3=3 which we have previosly stored in the dp array so from there we can get that and decide the minimum the number of coins .
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        if(dp[amount] == amount + 1)
            return -1;

        return dp[amount];
    }
};
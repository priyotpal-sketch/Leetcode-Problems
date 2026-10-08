// time complexity and space comleixty will be both O(n) as we creating a dp array 
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i / 2] + (i % 2);
        }

        return dp;
    }
};
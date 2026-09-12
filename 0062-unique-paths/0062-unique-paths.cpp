// The number of ways to reach me = ways to reach the cell above me + ways to reach the cell on my left
// the time complexity will  be O(m*n) as we there are m*n boxex which we will be visiting one by one also the space complexity will be O(m*n) as we making a 2D vector of that size
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
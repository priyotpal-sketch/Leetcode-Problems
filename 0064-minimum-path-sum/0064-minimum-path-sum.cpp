// time complexity of this approach will be O(m*n) as we are visitng every index of the grid , main target here is to calculate the minimum sum to reach the every index of the grid and replace the index with the path sum ,then at the last index we automatically get the minimum sum path ,this is approach of dp .
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

     
        for(int i = 1; i < m; i++) {
            grid[i][0] += grid[i-1][0];
        }

       
        for(int j = 1; j < n; j++) {
            grid[0][j] += grid[0][j-1];
        }

        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[m-1][n-1];
    }
};
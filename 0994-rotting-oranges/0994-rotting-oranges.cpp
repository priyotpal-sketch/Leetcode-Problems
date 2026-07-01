class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2)
                    q.push({i,j});

                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;

        int minutes = 0;

        while(!q.empty()) {

            int size = q.size();
            bool changed = false;

            for(int i = 0; i < size; i++) {

                int row = q.front().first;
                int col = q.front().second;
                q.pop();

            
                if(row-1 >= 0 && grid[row-1][col] == 1) {
                    grid[row-1][col] = 2;
                    q.push({row-1,col});
                    fresh--;
                    changed = true;
                }

                
                if(row+1 < n && grid[row+1][col] == 1) {
                    grid[row+1][col] = 2;
                    q.push({row+1,col});
                    fresh--;
                    changed = true;
                }

                
                if(col-1 >= 0 && grid[row][col-1] == 1) {
                    grid[row][col-1] = 2;
                    q.push({row,col-1});
                    fresh--;
                    changed = true;
                }

            
                if(col+1 < m && grid[row][col+1] == 1) {
                    grid[row][col+1] = 2;
                    q.push({row,col+1});
                    fresh--;
                    changed = true;
                }
            }

            if(changed)
                minutes++;
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};
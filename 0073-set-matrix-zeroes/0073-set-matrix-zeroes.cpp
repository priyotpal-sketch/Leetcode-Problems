// Time complexity of this approach will be time taken to find the 0 in each row and column which will be O(m*n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> rows;
        unordered_set<int> cols;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        
        for (int i : rows) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }

        for (int j : cols) {
            for (int i = 0; i < m; i++) {
                matrix[i][j] = 0;
            }
        }
    }
};
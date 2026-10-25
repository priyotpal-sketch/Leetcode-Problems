// time compleixty of this approach will be O(n^2) and space complexity will also be O(n^2) bcoz we creating a matrix of n^2 ,themain thing here is to change the boundaries each time you move in a row or column .
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int num = 1;

        while (top <= bottom && left <= right) {

            
            for (int j = left; j <= right; j++) {
                ans[top][j] = num++;
            }
            top++;

            
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = num++;
            }
            right--;

            
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans[bottom][j] = num++;
                }
                bottom--;
            }

            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = num++;
                }
                left++;
            }
        }

        return ans;
    }
};
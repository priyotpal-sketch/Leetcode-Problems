class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        int sr = 0;
        int er = rows - 1;

        
        while(sr <= er){

            int mid = sr + (er - sr)/2;

            if(matrix[mid][0] <= target &&
               target <= matrix[mid][cols-1]){

                
                int s = 0;
                int e = cols - 1;

                while(s <= e){

                    int m = s + (e-s)/2;

                    if(matrix[mid][m] == target){
                        return true;
                    }
                    else if(matrix[mid][m] < target){
                        s = m + 1;
                    }
                    else{
                        e = m - 1;
                    }
                }

                return false;
            }

            else if(target > matrix[mid][cols-1]){
                sr = mid + 1;
            }

            else{
                er = mid - 1;
            }
        }

        return false;
    }
};
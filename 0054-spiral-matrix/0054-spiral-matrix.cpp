class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int col=0;
        int row=0;
        int erow=n-1;
        int ecol=m-1;
        
            while(row<=erow && col<=ecol){

        for(int i=col;i<=ecol;i++){
            ans.push_back(matrix[row][i]);
        }
        for(int i=row+1;i<=erow;i++){
             ans.push_back(matrix[i][ecol]);
        }
        for(int i=ecol-1;i>=col;i--){
            if(row==erow){
                break;
            }
             ans.push_back(matrix[erow][i]);
        }
        for(int i=erow-1;i>=row+1;i--){
            if(col==ecol){
                break;
            }
             ans.push_back(matrix[i][col]);
        }
        col++;
        row++;
        erow--;
        ecol--;
        }
        
        return ans;

    
        
        
    }
};
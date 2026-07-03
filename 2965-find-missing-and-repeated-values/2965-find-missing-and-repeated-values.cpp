class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>ans;
        unordered_set<int>m;
        long long actualsum=0;
        int a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actualsum+=grid[i][j];
                if(m.find(grid[i][j])!=m.end()){
                     a=grid[i][j];
                        ans.push_back(grid[i][j]);
                        
                }
                m.insert(grid[i][j]);
                
            }
        }
            int expsum=(n*n)*(n*n+1)/2;
            b=expsum-actualsum+a;
            ans.push_back(b);
            return ans;
        
     
    }
};
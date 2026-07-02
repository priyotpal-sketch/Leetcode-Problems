class Solution {
public:

    void solve(vector<int>& candidates, int target,vector<int>& temp,vector<vector<int>>& ans,int idx){
            if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(target < 0 || idx >= candidates.size()) {
            return;
        }
        temp.push_back(candidates[idx]);

        solve(candidates,target - candidates[idx],temp,ans,idx);
              

        temp.pop_back();

        solve(candidates,
              target,
              temp,
              ans,
              idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates, target, temp, ans, 0);

        return ans;
    }
};
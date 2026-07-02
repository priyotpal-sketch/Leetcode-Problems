class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& temp, int idx) {
    
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);      
            solve(nums, temp, i + 1);     
            temp.pop_back();              
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums, temp, 0);
        return ans;
    }
};
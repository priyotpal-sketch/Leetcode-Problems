// time complexity will be O(nlogn) because we sorting the 2D array as well and spacecomplexity will be O(n) as we creating  a 2D vector ans , look here since ans is 2D vector ans.back() give the last 1D array inside it and ans.back()[1] gives last element of that 1D array which we are using here to compare 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); i++) {
            if(ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
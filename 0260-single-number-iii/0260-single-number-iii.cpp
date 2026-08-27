// Time complexity of this approach will be O(n) and this is same as its part 2 question
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        unordered_map<int, int> mp;

        
        for (int x : nums) {
            mp[x]++;
        }

        vector<int> ans;

        
        for (auto it : mp) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
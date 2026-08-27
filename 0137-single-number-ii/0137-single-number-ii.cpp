// Time complexity of this approach will be O(n) as we are visiting each and every value once
// there can other ways to 
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto it : mp) {
            if (it.second == 1) {
                return it.first;
            }
        }

        return -1;
    }
};
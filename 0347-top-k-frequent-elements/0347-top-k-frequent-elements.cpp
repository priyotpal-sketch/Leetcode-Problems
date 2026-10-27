
// this is m brute force approach idea having O(n) time complexity and extra space used here will be O(m)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        vector<pair<int, int>> arr;

        for (auto p : freq) {
            arr.push_back({p.second, p.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};
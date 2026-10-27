// this is my brute force approach idea for solving this probem having time complexity O(nlogn)
// class Solution {
// public:
//     int maximumGap(vector<int>& nums) {
//         if (nums.size() < 2)
//             return 0;

//         sort(nums.begin(), nums.end());

//         int maxDiff = 0;

//         for (int i = 1; i < nums.size(); i++) {
//             int diff = nums[i] - nums[i - 1];

//             if (diff > maxDiff) {
//                 maxDiff = diff;
//             }
//         }

//         return maxDiff;
//     }
// };
// this is the required optimal solution
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        if (mn == mx) return 0;

        int size = max(1, (mx - mn) / (n - 1));
        int count = (mx - mn) / size + 1;

        vector<int> low(count, INT_MAX);
        vector<int> high(count, INT_MIN);

        for (int x : nums) {
            int i = (x - mn) / size;
            low[i] = min(low[i], x);
            high[i] = max(high[i], x);
        }

        int ans = 0, prev = mn;

        for (int i = 0; i < count; i++) {
            if (low[i] == INT_MAX) continue;

            ans = max(ans, low[i] - prev);
            prev = high[i];
        }

        return ans;
    }
};
// This is my brute force appraoch idea using two loops but this will give time limit for very large nums so it will not work that's why a second solution is written below with O(nlogk) time complexity ,which is solution from chatgpt 
// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {

//                 if (j - i <= indexDiff &&
//                     abs((long long)nums[i] - nums[j]) <= valueDiff) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;

        for (int i = 0; i < nums.size(); i++) {
            
            // Find the smallest number >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            // If it exists and is <= nums[i] + valueDiff
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            // Add current element
            window.insert(nums[i]);

            // Keep only the last indexDiff elements
            if (i >= indexDiff) {
                window.erase(nums[i - indexDiff]);
            }
        }

        return false;
    }
};
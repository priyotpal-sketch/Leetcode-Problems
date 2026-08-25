// Time complexity will be O(n^3) for this brute force approach 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {

                    int sum = nums[i] + nums[j] + nums[k];

                    if (abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }
                }
            }
        }

        return closest;
    }
};
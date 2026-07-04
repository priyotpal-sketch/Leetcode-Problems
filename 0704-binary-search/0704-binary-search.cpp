class Solution {
public:
    int targetsearch(vector<int>& nums, int st, int end, int target) {
        if(st > end) return -1;

        int mid = st + (end - st) / 2;

        if(nums[mid] == target) {
            return mid;
        }
        else if(target < nums[mid]) {
            return targetsearch(nums, st, mid - 1, target);
        }
        else {
            return targetsearch(nums, mid + 1, end, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return targetsearch(nums, 0, nums.size() - 1, target);
    }
};
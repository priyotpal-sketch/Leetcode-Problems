// this is my brute force approach will take time complexity O(n) and sapce complexity O(n) as we created 2 vctors 
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        vector<int> task;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                ans.push_back(nums[i]);
            } else {
                task.push_back(nums[i]);
            }
        }

      
        for (int i = 0; i < task.size(); i++) {
            if (task[i] == pivot) {
                ans.push_back(task[i]);
            }
        }

        
        for (int i = 0; i < task.size(); i++) {
            if (task[i] > pivot) {
                ans.push_back(task[i]);
            }
        }

        return ans;
    }
};
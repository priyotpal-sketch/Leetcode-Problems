// This is the approach which I have used but in this appraoch ,it is taking O(n) space which is prohibited here 
// class Solution {
// public:
//     vector<int> findDuplicates(vector<int>& nums) {
//         unordered_set<int> st;
//         vector<int> ans;

//         for (int x : nums) {

//             if (st.count(x)) {
//                 ans.push_back(x);
//             }
//             else {
//                 st.insert(x);
//             }
//         }

//         return ans;
//     }
// };
// This is the way that I have know from chatgpt which is following all constraints given for this question
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);

            if (nums[x - 1] < 0) {
                ans.push_back(x);
            }
            else {
                nums[x - 1] = -nums[x - 1];
            }
        }

        return ans;
    }
};
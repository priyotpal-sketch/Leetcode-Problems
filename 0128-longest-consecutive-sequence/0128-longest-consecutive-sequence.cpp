// this is my brute force appraoch idea where I solved this question in O(nlogn) time complexity coz it uses a sorting 
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
        
//         if(nums.size() == 0)
//             return 0;

//         sort(nums.begin(), nums.end());

//         int count = 1;
//         int maxCount = 1;

//         for(int i = 1; i < nums.size(); i++) {

          
//             if(nums[i] == nums[i - 1]) {
//                 continue;
//             }

            
//             if(nums[i] == nums[i - 1] + 1) {
//                 count++;
//             }

           
//             else {
//                 maxCount = max(maxCount, count);
//                 count = 1;
//             }
//         }

     
//         maxCount = max(maxCount, count);

//         return maxCount;
//     }
// };
// this is approach which I take help from AI to understand 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for(int num : nums) {
            st.insert(num);
        }

        int maxCount = 0;

        for(int num : st) {

          
            if(st.count(num - 1) == 0) {

                int current = num;
                int count = 1;
   while(st.count(current + 1)) {
                    current++;
                    count++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};
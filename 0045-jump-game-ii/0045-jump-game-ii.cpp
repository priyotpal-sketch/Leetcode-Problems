// Time complexity will be O(n)
// Actually we have to find that how farthest we can while living under our current limit such that we can reach the last index that's why we will increase the jumps only if we reach the limit of our current jump 
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {

            
            farthest = max(farthest, i + nums[i]);

            
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int min = 1;  
        int max = 2;  

        for (int i = 3; i <= n; i++) {
            int curr = max + min;
            min = max;
            max = curr;
        }

        return max;
    }
};
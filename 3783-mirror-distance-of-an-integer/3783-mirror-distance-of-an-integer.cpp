// Time complexity of thi appraoch will be O(logn),focus on that we not running the loop n time instead we are running it for digits count of that number .
class Solution {
public:
    int mirrorDistance(int n) {
        int original = n;
        int rev = 0;

        while (n > 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }

        return abs(original - rev);
    }
};
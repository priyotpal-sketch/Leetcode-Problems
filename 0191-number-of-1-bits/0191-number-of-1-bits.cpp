//time complexity will be O(logn) and space complexity will be o(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while(n > 0) {
            if(n % 2 == 1)
                count++;

            n = n / 2;
        }

        return count;
    }
};
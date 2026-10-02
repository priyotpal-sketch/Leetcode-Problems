// time complexity of m brute force approach will be O(2^n) which is very high for large numbers so this is optimal approach and space complexity will b O(1) as are creating a vector of constant size 
// bruteforce apraoch of this idea is O(n) and space complexity will be O(n) a we creating a recursive stack
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;

        int mid = 1 << (n - 2);

        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } 
        else {
            return 1 - kthGrammar(n - 1, k - mid);
        }
    }
};

class Solution {
public:
    int sumSquare(int num) {
        int sum = 0;

        while (num > 0) {
            int rem = num % 10;
            sum += rem * rem;
            num = num / 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sumSquare(n);
        }

        return n == 1;
    }
};
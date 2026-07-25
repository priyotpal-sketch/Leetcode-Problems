// The concept here is that until the number becomes didvde it by all the three required numbers such that only factors prime will only be these 
class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0)
            return false;

        while (n % 2 == 0)
            n /= 2;

        while (n % 3 == 0)
            n /= 3;

        while (n % 5 == 0)
            n /= 5;

        return n == 1;
    }
};
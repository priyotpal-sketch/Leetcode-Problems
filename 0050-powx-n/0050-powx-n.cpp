class Solution {
public:
    double myPow(double x, int n) {
        long binaryform = n;

        if(n == 0) return 1;
        if(x == 0) return 0;
        if(x == 1) return 1;

        if(n < 0) {
            x = 1 / x;
            binaryform = -binaryform;
        }

        double ans = 1;

        while(binaryform > 0) {
            if(binaryform % 2 == 1) {
                ans = ans * x;
            }

            x = x * x;
            binaryform = binaryform / 2;
        }

        return ans;
    }
};
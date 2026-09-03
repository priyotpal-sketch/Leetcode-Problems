// Time complexity of this greedy approach will be O(logn) bcoz each time either we dividing by 2 or adding 1 or subtracting 1 then dividing by 2 ,The most important thing here is to understand the difference even in the nature of odd numbers except 3 which is a special case 
class Solution {
public:
    int integerReplacement(int n) {

        long long x = n;
        int count = 0;

        while (x != 1) {

            
            if (x % 2 == 0) {
                x = x / 2;
            }

            
            else {

                
                if (x == 3) {
                    x = x - 1;
                }

                
                else if (x % 4 == 1) {
                    x = x - 1;
                }

                
                else {
                    x = x + 1;
                }
            }

            count++;
        }

        return count;
    }
};
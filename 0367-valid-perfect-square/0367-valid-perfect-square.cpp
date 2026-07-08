// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         if (num == 1) return true;

//         for (int i = 1; i <= num / 2; i++) {
//             if (num / i == i && num % i == 0) {
//                 return true;
//             }
//         }

//         return false;
//     }
// };
class Solution {
public:
    bool isPerfectSquare(int num) {
        int min=1;
        int max=num;

        while (min<= max) {
            long long mid = min + (max- min) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            }
            else if (square < num) {
                min = mid + 1;
            }
            else max = mid - 1;
        }

        return false;
    }
};
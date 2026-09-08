// time complexity will be O(1) and space complexity will also be O(1) ,as we are taking no etra space .
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};
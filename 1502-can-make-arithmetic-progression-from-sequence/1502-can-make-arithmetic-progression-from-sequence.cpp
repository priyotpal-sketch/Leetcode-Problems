// time complexity will be O(nlogn) and space complexity will be O(n) as there will space required inside the sorting method which creates a internal stack
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int diff = arr[1] - arr[0];

        for(int i = 2; i < arr.size(); i++) {
            if(arr[i] - arr[i - 1] != diff)
                return false;
        }

        return true;
    }
};
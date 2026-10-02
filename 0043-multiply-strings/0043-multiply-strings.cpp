// time complexity of this appraoch will be O(m*n) and space complexity will be O(m+n) , basically we are doing same process which we do while multiplying two number ,first upperrightmost number with each digit of lower number and then we move towards one digit left in upper number and then find the carry and sum and write answer according to that after doing final sum 
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size();
        int n = num2.size();

        vector<int> ans(m + n, 0);

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {

                int a = num1[i] - '0';
                int b = num2[j] - '0';

                int product = a * b;

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int sum = product + ans[pos2];

                ans[pos2] = sum % 10;
                ans[pos1] += sum / 10;
            }
        }

        string result = "";

        for(int x : ans) {
            if(result.empty() && x == 0)
                continue;

            result += char(x + '0');
        }

        return result;
    }
};
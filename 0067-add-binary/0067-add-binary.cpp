// Time complexity will be O(max(n,m))
// we just have add like normal addition we do in our copy ,just focus on how to find the carry and bit then in last reverse 
class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            ans += (sum % 2) + '0';

            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
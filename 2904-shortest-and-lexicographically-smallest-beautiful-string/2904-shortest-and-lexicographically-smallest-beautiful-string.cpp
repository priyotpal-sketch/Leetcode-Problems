// Time complexity will be 0(n^2) , approach is based on sliding window approach where you have to find the valid substring then compare them on the basis of their length and the smallest one will be the answer 
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int left = 0;
        int count = 0;

        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            if (s[right] == '1')
                count++;

            while (count == k) {

                string curr = s.substr(left, right - left + 1);

                if (ans == "" || curr.length() < ans.length() ||
                   (curr.length() == ans.length() && curr < ans)) {
                    ans = curr;
                }

                if (s[left] == '1')
                    count--;

                left++;
            }
        }

        return ans;
    }
};
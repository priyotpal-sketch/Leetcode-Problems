// Reverse the first rk characters for first k characters that means for example 1 the string will be divided into two blocks of four characters each abcd and efg and two characters from each beginning will be reversed
class Solution {
public:
    void reverse(string &s, int left, int right)
    {
        while (left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    string reverseStr(string s, int k)
    {
        int n = s.length();

        for (int i = 0; i < n; i += 2 * k)
        {
            int end = min(i + k - 1, n - 1);
            reverse(s, i, end);
        }

        return s;
    }
};
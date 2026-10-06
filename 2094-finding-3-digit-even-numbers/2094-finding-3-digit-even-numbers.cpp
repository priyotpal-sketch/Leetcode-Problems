// time complexity will be O(1) as we are checking all the numbers between 100 and 999 which is even ,so timetime complexity will be constant and space complexity will be constant as well as are making vector of constant space 
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        
        for(int x : digits) {
            freq[x]++;
        }

        vector<int> ans;

        for(int num = 100; num <= 998; num++) {

           
            if(num % 2 != 0)
                continue;

            int a = num / 100;        
            int b = (num / 10) % 10;  
            int c = num % 10;         

            freq[a]--;
            freq[b]--;
            freq[c]--;


            if(freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0) {
                ans.push_back(num);
            }

           
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }

        return ans;
    }
};
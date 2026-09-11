// the time complexity of this brute force approach will be O(nlogn) , focus on that code that we arenot running the loop n times ,its getting divided by n,n/2,n/3 ,so aprx imecomplexity will be O(nlogn) and also space complexity will be O(n) as created a vector bulb .the concept here is simple that toggle the ith bulb at every ith  round and in last just return which are left ON .
// class Solution {
// public:
//     int bulbSwitch(int n) {
//         vector<bool> bulb(n + 1, false);

//         for (int round = 1; round <= n; round++) {

//             for (int i = round; i <= n; i += round) {
//                 bulb[i] = !bulb[i];
//             }
//         }

//         int ans = 0;

//         for (int i = 1; i <= n; i++) {
//             if (bulb[i])
//                 ans++;
//         }

//         return ans;
//     }
// };
// this solution I have done by using hint from leetcode
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
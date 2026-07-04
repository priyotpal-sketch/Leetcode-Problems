class Solution {
public:
    bool issamefreq(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for(int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windsize = s1.length();

        if(s2.length() < windsize) return false;

        for(int i = 0; i <= s2.length() - windsize; i++) {
            int windfreq[26] = {0};

            for(int j = 0; j < windsize; j++) {
                windfreq[s2[i + j] - 'a']++;
            }

            if(issamefreq(freq, windfreq)) {
                return true;
            }
        }

        return false;
    }
};
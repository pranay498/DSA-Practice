class Solution {
public:
    int minSteps(string s, string t) {
          unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        int ans = 0;

        for (char ch : t) {
            if (freq[ch] > 0) {
                freq[ch]--;
            } else {
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        long long power = 1;

        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == '0') {
                ans++;
            }
            else {
                if (power <= k) {
                    k -= power;
                    ans++;
                }
            }
            if (power <= k)
                power *= 2;
        }

        return ans;
    }
};
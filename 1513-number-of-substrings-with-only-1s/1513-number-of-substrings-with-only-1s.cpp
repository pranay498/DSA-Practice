class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        long long count = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '1') {
                count++;
                ans += count;
            } else {
                count = 0;
            }
        }

        return ans % 1000000007;
    }
};
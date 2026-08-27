class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int l = 0;
        int ones = 0;

        string ans = "";

        for (int r = 0; r < s.size(); r++) {

            if (s[r] == '1')
                ones++;

            while (ones > k) {
                if (s[l] == '1')
                    ones--;

                l++;
            }

            while (ones == k && s[l] == '0') {
                l++;
            }

            if (ones == k) {

                string curr = s.substr(l, r - l + 1);

                if (ans == "" || curr.length() < ans.length() ||
                    (curr.length() == ans.length() && curr < ans)) {

                    ans = curr;
                }
            }
        }

        return ans;
    }
};
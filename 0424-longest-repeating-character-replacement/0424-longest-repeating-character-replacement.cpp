class Solution {
public:
    int characterReplacement(string s, int k) {

        int ans = 0;
        vector<bool> present(26, false);

        for (char c : s) {
            present[c - 'A'] = true;
        }

        for (int i = 0; i < 26; i++) {

            if (!present[i])
                continue;

            char ch = 'A' + i;

            int left = 0;
            int count = 0;

            for (int right = 0; right < s.size(); right++) {

                if (s[right] == ch)
                    count++;

                while ((right - left + 1) - count > k) {

                    if (s[left] == ch)
                        count--;

                    left++;
                }

                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};
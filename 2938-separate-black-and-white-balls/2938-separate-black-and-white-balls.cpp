class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0;
        long long swaps = 0;

        for (char ch : s) {

            if (ch == '1') {
                ones++;
            } else {
                swaps += ones;
            }
        }

        return swaps;
    }
};
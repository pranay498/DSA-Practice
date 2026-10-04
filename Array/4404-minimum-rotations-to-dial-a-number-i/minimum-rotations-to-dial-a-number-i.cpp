class Solution {
public:
    int minRotations(string s) {
         int ans = 0;
        int curr = 0;

        for (char ch : s) {

            int next = ch - '0';

            int clockwise = (next - curr + 10) % 10;
            int anticlockwise = (curr - next + 10) % 10;

            ans += min(clockwise, anticlockwise);

            curr = next;
        }

        return ans;
    }
};
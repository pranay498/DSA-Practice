class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;

        for (int x : rolls) {
            sum += x;
        }

        int totalSum = (rolls.size() + n) * mean;

        int missingSum = totalSum - sum;

        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }

        vector<int> ans(n);

        int base = missingSum / n;
        int rem = missingSum % n;

        for (int i = 0; i < n; i++) {
            ans[i] = base;

            if (rem > 0) {
                ans[i]++;
                rem--;
            }
        }

        return ans;
    }
};
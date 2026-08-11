class Solution {
public:

    const int MOD = 1e9 + 7;
    int dp[301][301];

    int solve(int idx, int n, vector<int>& result) {
        if (n == 0)
            return 1;

        if (n < 0 || idx == result.size())
            return 0;

        if (dp[idx][n] != -1)
            return dp[idx][n];

        long long take = solve(idx + 1, n - result[idx], result);

        long long not_take = solve(idx + 1, n, result);

        return dp[idx][n] = (take + not_take) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<int> result;

        memset(dp, -1, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            int power = pow(i, x);

            if (power > n)
                break;

            result.push_back(power);
        }

        return solve(0, n, result);
    }
};
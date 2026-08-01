class Solution {
public:
    vector<vector<int>> dp;
    const int MOD = 1e9 + 7;

    int solve(int n, int k, int target) {

        if (n == 0) {
            if (target == 0)
                return 1;
            return 0;
        }

        if (target < 0)
            return 0;

        if (dp[n][target] != -1)
            return dp[n][target];

        int result = 0;

        for (int face = 1; face <= k; face++) {
           result = (result + solve(n - 1, k, target - face)) % MOD;
        }

        return dp[n][target] = result;
    }

    int numRollsToTarget(int n, int k, int target) {

        dp.resize(n + 1, vector<int>(target + 1, -1));

        return solve(n, k, target);
    }
};
class Solution {
public:
    int MOD = 1e9 + 7;

    int dp[5001][7][16];

    int solve(int pos, int last, int count, int n, vector<int>& rollMax) {
        // Base case: n rolls completed
        if (pos == n) {
            return 1;
        }


        if (dp[pos][last][count] != -1) {
            return dp[pos][last][count];
        }

        long long ans = 0;

        // Try rolling numbers 1 to 6
        for (int num = 1; num <= 6; num++) {
            if (num == last) {
    
                if (count < rollMax[num - 1]) {
                    ans = (ans + solve(pos + 1, num, count + 1, n, rollMax)) % MOD;
                }
            } else {
     
                ans = (ans + solve(pos + 1, num, 1, n, rollMax)) % MOD;
            }
        }

    
        return dp[pos][last][count] = ans;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, n, rollMax);
    }
};
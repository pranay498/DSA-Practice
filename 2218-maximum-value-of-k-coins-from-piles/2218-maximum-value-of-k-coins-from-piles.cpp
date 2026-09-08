class Solution {
public:
    int dp[1001][2001];
    int solve(int idx, vector<vector<int>>& piles, int k) {
        if (idx >= piles.size())
            return 0;
        if(dp[idx][k]!=-1)
        return dp[idx][k];

        int take = 0;
        int sum = 0;

        for (int i = 0; i < piles[idx].size() && i < k; i++) {

             sum += piles[idx][i];

            int current = sum + solve(idx + 1, piles, k - (i + 1));

            take = max(take, current);
        }

        int not_take = solve(idx + 1, piles, k);

        return dp[idx][k] = max(take, not_take);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0, piles, k);
    }
};
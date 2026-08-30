class Solution {
public:

 int dp[601][101][101];

    int solve(int i, int m, int n, vector<pair<int, int>>& count) {

        if (i == count.size()) {
            return 0;
        }

        if(dp[i][m][n]!=-1)
        return dp[i][m][n];

        int zeros = count[i].first;
        int ones = count[i].second;

        int take = 0;

        if (zeros <= m && ones <= n) {
            take = 1 + solve(i + 1, m - zeros, n - ones, count);
        }

        int skip = solve(i + 1, m, n, count);

        return dp[i][m][n] = max(take, skip);
    } 

    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<pair<int, int>> count;

        for (string s : strs) {

            int zeros = 0;
            int ones = 0;

            for (char ch : s) {
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            }

            count.push_back({zeros, ones});
        }
         memset(dp, -1, sizeof(dp));

        return solve(0, m, n, count);
    }
};
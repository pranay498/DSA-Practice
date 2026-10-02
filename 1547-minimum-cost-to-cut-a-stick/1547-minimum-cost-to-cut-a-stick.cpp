class Solution {
public:
    int solve(vector<int>& cuts, int l, int r ,vector<vector<int>>& dp) {
        if (r - l < 2)
            return 0;

         if (dp[l][r] != -1)
            return dp[l][r];    

        int result = INT_MAX;

        for (int index = l + 1; index <= r - 1; index++) {

            int cost = (cuts[r] - cuts[l])+ solve(cuts, l, index,dp) + solve(cuts, index, r,dp);
            result = min(result, cost);
        }

        return dp[l][r] =result;
    }

    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(), cuts.end());

        cuts.insert(begin(cuts), 0);
        cuts.push_back(n);

        int size = cuts.size();


        vector<vector<int>> dp(size, vector<int>(size, -1));

        return solve(cuts, 0, cuts.size() - 1,dp);
    }
};
class Solution {
public:
    vector<int> dp;
    int solve(int i, string& s) {
    
        if (i == s.size())
            return 1;

        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int take = 0;
        int notTake = 0;

        take = solve(i + 1, s);

        if (i + 1 < s.size() &&
            (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {

            notTake = solve(i + 2, s);
        }

          return dp[i] = take + notTake;
    }

    int numDecodings(string s){
         dp.resize(s.size(), -1);
         return solve(0, s);
      }
};
class Solution {
public:
 int dp[51];
    int solve(int i, string s, unordered_map<string, int>& mp) {
        if (i == s.size())
            return 0;
        
        if(dp[i]!=-1)
        return dp[i];

        int skip = 1 + solve(i + 1, s, mp);

        int ans = skip;

        string temp = "";

        for (int j = i; j < s.size(); j++) {

            temp += s[j];

            if (mp.find(temp) != mp.end()) {
                int take = solve(j + 1, s, mp);
                ans = min(ans, take);
            }
        }

        return dp[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        memset(dp,-1,sizeof(dp));

        unordered_map<string, int> mp;

        for (int i = 0; i < dictionary.size(); i++) {
            mp[dictionary[i]]++;
        }
        return solve(0, s, mp);
    }
};
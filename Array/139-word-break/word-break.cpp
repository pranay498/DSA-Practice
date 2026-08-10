class Solution {
public:
   int dp[301];
    bool solve(string& s, unordered_set<string>& wordDict, int index) {
        if(index==s.length()) {
            return true;
        }

        if(dp[index] != -1) return dp[index];
        
        for(int i=index; i<s.length(); i++) {
            if(wordDict.find(s.substr(index, i-index+1)) != wordDict.end()) {
                if(solve(s, wordDict, i+1)) return true;
            }
        }

        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        unordered_set<string> st;
        st.insert(wordDict.begin(), wordDict.end());
        return solve(s, st, 0);  
    }
};
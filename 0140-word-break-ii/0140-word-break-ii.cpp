class Solution {
public:
    vector<string> ans;
    unordered_set<string> st;

    void solve(string s, int i, string current) {

        if (i == s.size()) {
            ans.push_back(current);
            return;
        }

        string word = "";

        for (int j = i; j < s.size(); j++) {

            word += s[j];

            if (st.count(word)) {

                string next = current;

                if (next != "")
                    next += " ";

                next += word;

                solve(s, j + 1, next);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        for (string word : wordDict)
            st.insert(word);

        solve(s, 0, "");

        return ans;
    }
};
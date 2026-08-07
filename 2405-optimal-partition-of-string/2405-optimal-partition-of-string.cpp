class Solution {
public:
    int partitionString(string s) {
        
        unordered_set<char> st;
        int ans = 1;

        for (char ch : s) {

            if (st.count(ch)) {
                ans++;
                st.clear();
            }

            st.insert(ch);
        }

        return ans;
    }
};
class Solution {
public:
    int minimumDeletions(string word, int k) {

        vector<int> freq(26, 0);

        for(char c : word) {
            freq[c - 'a']++;
        }

        int ans = word.size();

        for(int x : freq) {

            if(x == 0) continue;

            int deletions = 0;

            for(int f : freq) {

                if(f == 0) continue;

                if(f < x) {
                    deletions += f;
                }
                else if(f > x + k) {
                    deletions += f - (x + k);
                }
            }

            ans = min(ans, deletions);
        }

        return ans;
    }
};
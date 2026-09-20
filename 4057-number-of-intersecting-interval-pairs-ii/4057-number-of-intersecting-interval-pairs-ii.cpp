class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> starts;
        vector<int> ends;

        for (auto &x : intervals) {
            starts.push_back(x[0]);
            ends.push_back(x[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        long long ans = 0;

        int j = 0;

        for (int i = 0; i < n; i++) {

            while (j < n && ends[j] < starts[i]) {
                j++;
            }

            ans += i - j;
        }

        return ans;
    }
};
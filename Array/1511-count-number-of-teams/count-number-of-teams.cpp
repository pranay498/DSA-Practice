class Solution {
public:
 int dpInc[1001][1002][4];
    int dpDec[1001][1002][4];

    int increasing(vector<int>& rating, int idx, int prev, int taken) {

        if (taken == 3)
            return 1;

        if (idx == rating.size())
            return 0;

        if (dpInc[idx][prev + 1][taken] != -1)
            return dpInc[idx][prev + 1][taken];

        int take = 0;

        if (prev == -1 || rating[idx] > rating[prev])
            take = increasing(rating, idx + 1, idx, taken + 1);

        int skip = increasing(rating, idx + 1, prev, taken);

        return dpInc[idx][prev + 1][taken] = take + skip;
    }

    int decreasing(vector<int>& rating, int idx, int prev, int taken) {

        if (taken == 3)
            return 1;

        if (idx == rating.size())
            return 0;

        if (dpDec[idx][prev + 1][taken] != -1)
            return dpDec[idx][prev + 1][taken];

        int take = 0;

        if (prev == -1 || rating[idx] < rating[prev])
            take = decreasing(rating, idx + 1, idx, taken + 1);

        int skip = decreasing(rating, idx + 1, prev, taken);

        return dpDec[idx][prev + 1][taken] = take + skip;
    }

    int numTeams(vector<int>& rating) {

        memset(dpInc, -1, sizeof(dpInc));
        memset(dpDec, -1, sizeof(dpDec));

        return increasing(rating, 0, -1, 0) +
               decreasing(rating, 0, -1, 0);
    }
};
class Solution {
public:
    int check(vector<int>& tops, vector<int>& bottoms, int x) {
        int topRot = 0;
        int bottomRot = 0;

        for (int i = 0; i < tops.size(); i++) {

            if (tops[i] != x && bottoms[i] != x)
                return -1;

            if (tops[i] != x)
                topRot++;

            if (bottoms[i] != x)
                bottomRot++;
        }

        return min(topRot, bottomRot);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;

        for (int x = 1; x <= 6; x++) {
            int rotations = check(tops, bottoms, x);

            if (rotations != -1)
                ans = min(ans, rotations);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
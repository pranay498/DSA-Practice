class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = target.size();
        vector<int> ans(n);

        if (triplets.size() == 1) {
            ans[0] = triplets[0][0];
            ans[1] = triplets[0][1];
            ans[2] = triplets[0][2];

            return ans == target;
        }

        for (auto& triplet : triplets) {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] &&
                triplet[2] <= target[2]) {
                ans[0] = max(ans[0], triplet[0]);
                ans[1] = max(ans[1], triplet[1]);
                ans[2] = max(ans[2], triplet[2]);
            }
        }

        return ans == target;
    }
};
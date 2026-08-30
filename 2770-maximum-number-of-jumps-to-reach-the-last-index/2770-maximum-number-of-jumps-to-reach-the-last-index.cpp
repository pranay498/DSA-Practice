class Solution {
public:

    int solve(int i, vector<int>& nums, int target,
              vector<int>& dp) {

        if (i == nums.size() - 1) {
            return 0;
        }

        if (dp[i] != -2) {
            return dp[i];
        }

        int ans = -1;

        for (int j = i + 1; j < nums.size(); j++) {

            if (abs(nums[i] - nums[j]) <= target) {

                int jumps = solve(j, nums, target, dp);

                if (jumps != -1) {
                    ans = max(ans, 1 + jumps);
                }
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        int n = nums.size();

        vector<int> dp(n, -2);

        return solve(0, nums, target, dp);
    }
};
class Solution {
public: 
     int dp[2501][2501];
    int solve(int idx, int prev, vector<int>& nums) {

        if(idx>=nums.size())
        return 0 ;

         if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int take = 0;

        if (prev == -1 || nums[prev] < nums[idx]) 
        {
         take = 1 + solve(idx + 1, idx , nums);
        }
        int not_take = solve(idx + 1, prev, nums);

        return dp[idx][prev + 1] = max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums)
     {
         memset(dp, -1, sizeof(dp));
         return solve(0, -1, nums);
    }
};
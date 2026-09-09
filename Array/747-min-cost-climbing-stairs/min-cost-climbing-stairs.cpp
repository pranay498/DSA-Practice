class Solution {
public:  
    //   int dp[1001];
      int solve(int i ,vector<int>&cost,vector<int>&dp)
      {
        if(i>=cost.size())
        return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=cost[i]+solve(i+1,cost,dp);
        int two=cost[i]+solve(i+2,cost,dp);
        dp[i]=min(one,two);
        return dp[i];
      }

    int minCostClimbingStairs(vector<int>& cost) {
        // memset(dp,-1,sizeof(dp));
        int n=cost.size();
       vector<int>dp(n,-1);
       return min(solve(0,cost,dp),solve(1,cost,dp));
       
    }
};
class Solution {
public:
    void totalSubset(vector<int>&nums ,int i ,vector<int>&temp ,vector<vector<int>>&result)
    {
        int n=nums.size();
        if(i==n){
        result.push_back(temp);
        return ;
        }
        totalSubset(nums,i+1,temp,result);
        temp.push_back(nums[i]);
        totalSubset(nums,i+1,temp,result);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>result;
        totalSubset(nums ,0,temp ,result);
        return result;
    }
};
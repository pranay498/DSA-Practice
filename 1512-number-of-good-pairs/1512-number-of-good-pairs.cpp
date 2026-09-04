class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count=0; 
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            int temp = nums[i];
            if(mp.find(temp)!= mp.end())
            {
                count+= mp[temp];
            }

            mp[temp]++;
        }

        return count;
    }
};
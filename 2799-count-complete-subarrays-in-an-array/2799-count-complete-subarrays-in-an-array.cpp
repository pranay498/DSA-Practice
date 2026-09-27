class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {

        int n =nums.size();
        
        unordered_set<int> st;

        int ans = 0 ,left=0;

        for(int i =0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        unordered_map<int,int>mp;

        for(int right=0; right<nums.size();right++)
        {
           mp[nums[right]]++;
            
            while(mp.size() == st.size())
            {
                ans+=(n-right);
                mp[nums[left]]--;

                if(mp[nums[left]]==0)
                mp.erase(nums[left]);

                left++;
            }
        }
        return ans;
    }
};
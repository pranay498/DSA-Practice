class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        int n = nums.size();

        int tuples = 0;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int num = nums[i] * nums[j];

                mp[num]++;
            }
        }

        for (auto& it : mp) {

            int u = it.first;
            int v = it.second;
            
            tuples += (v*(v-1))/2;
        }
        return tuples*8;
    }
};
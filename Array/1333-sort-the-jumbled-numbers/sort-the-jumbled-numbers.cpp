class Solution {
public:
    int getMappedNumber(int num, vector<int>& mapping) {
        if (num == 0)
            return mapping[0];

        vector<int> digits;

        while (num > 0) {
            digits.push_back(mapping[num % 10]);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());

        int mapped = 0;

        for (int x : digits) {
            mapped = mapped * 10 + x;
        }

        return mapped;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for (int i = 0; i < n; i++) {

            int num = nums[i];

            int result = getMappedNumber(num, mapping);

            vec.push_back({result, i});
        }

        vector<int> result;

        sort(vec.begin(), vec.end());

        for (int i = 0; i < n; i++) {
            int originalIndex = vec[i].second;

            result.push_back(nums[originalIndex]);
        }
        return result;
    }
};
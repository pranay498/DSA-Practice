class Solution {
public:
    int maximumSwap(int num) {
          string nums = to_string(num);
        string result = nums;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    string temp = nums;
                    swap(temp[i], temp[j]);

                    if (temp > result) {
                        result = temp;
                    }
                }
            }
        }
        return stoi(result);
    }
};
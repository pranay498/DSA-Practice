class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int sum = 0;
        double maxi = INT_MIN;

        for (int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            if (right - left + 1 == k) {

                double temp = (double)sum / k;

                maxi = max(maxi, temp);

                sum -= nums[left];
                left++;
            }
        }
        return maxi;
    }
};
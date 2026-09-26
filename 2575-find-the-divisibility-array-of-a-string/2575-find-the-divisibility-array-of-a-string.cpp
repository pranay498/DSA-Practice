class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
      int n = word.size();
        vector<int> arr(n, 0);

        long long rem = 0;

        for (int i = 0; i < n; i++) {
            
            int digit = word[i] - '0';

            rem = (rem * 10 + digit) % m;

            if (rem == 0) {
                arr[i] = 1;
            }
            else {
                arr[i] = 0;
            }
        }

        return arr;
    }
};
class Solution {
public:
    vector<string> result;
    int n;
   void  backtrack(int idx, string& temp, string& digits,unordered_map<char, string>& mp) {

        if (idx == digits.size()) {
            result.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string str = mp[ch];
        for (int i = 0; i < str.size(); i++) {
            temp.push_back(str[i]);
            backtrack(idx + 1, temp, digits, mp);
             temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        string temp = "";
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        backtrack(0, temp, digits, mp);

        return result;
    }
};
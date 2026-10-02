class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (!wordSet.count(endWord))
            return 0;

        queue<string> q;

        q.push(beginWord);

        int level = 1;

        while (!q.empty()) {

            int n = q.size();

            while (n--) {

                string curr = q.front();
                q.pop();

                if (curr == endWord)
                    return level;

                for (int i = 0; i < curr.size(); i++) {

                    char original = curr[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        curr[i] = ch;

                        if (wordSet.count(curr)) {
                            q.push(curr);
                            wordSet.erase(curr);
                        }
                    }

                    curr[i] = original;
                }
            }

            level++;
        }

        return 0;
    }
};
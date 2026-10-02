class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;

        queue<string> que;

        que.push(startGene);
        visited.insert(startGene);

        int level = 0;

        while (!que.empty()) {

            int n = que.size();

            while (n--) {

                string curr = que.front();
                que.pop();

                if (curr == endGene)
                    return level;

                string chars = "ACGT";

                for (char ch : chars) {

                    for (int i = 0; i < curr.size(); i++) {

                        string neighbour = curr;
                        neighbour[i] = ch;

                        if (bankSet.count(neighbour) &&
                            !visited.count(neighbour)) {

                            que.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        unordered_map<int, int> mp;
        vector<int> zeroLoss;
        vector<int> oneLoss;

        for (auto it : matches)
        {
            int loser = it[1];
            mp[loser]++;
        }

        unordered_set<int> players;

        for (auto it : matches)
        {
            players.insert(it[0]);
            players.insert(it[1]);
        }

        for (auto player : players)
        {
            if (mp.find(player) == mp.end())
            {
                zeroLoss.push_back(player);
            }
            else if (mp[player] == 1)
            {
                oneLoss.push_back(player);
            }
        }

        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {zeroLoss, oneLoss};
    }
};
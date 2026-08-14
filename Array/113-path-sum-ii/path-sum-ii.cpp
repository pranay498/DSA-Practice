/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
         vector<vector<int>> ans;
    vector<int> path;

    void solve(TreeNode* root, int targetSum, int sum) {

        if (root == NULL)
            return;

        path.push_back(root->val);
        sum += root->val;

        if (root->left == NULL && root->right == NULL) {

            if (sum == targetSum)
                ans.push_back(path);

            sum -= root->val;
            path.pop_back();
            return;
        }

        solve(root->left, targetSum, sum);
        solve(root->right, targetSum, sum);

        sum -= root->val;
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum, 0);
        return ans;
    }
};
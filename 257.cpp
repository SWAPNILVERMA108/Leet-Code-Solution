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

    vector<string> ans;

    void dfs(TreeNode* root, string path) {

        if(root == nullptr) {
            return;
        }

        // Add current node value
        path += to_string(root->val);

        // Leaf node
        if(root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        // Add arrow
        path += "->";

        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {

        dfs(root, "");

        return ans;
    }
};
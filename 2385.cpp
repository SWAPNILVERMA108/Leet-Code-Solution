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
    TreeNode* markParents(TreeNode* root,
                          unordered_map<TreeNode*, TreeNode*>& parent,
                          int start) {

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* target = nullptr;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start)
                target = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return target;
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* target = markParents(root, parent, start);

        unordered_map<TreeNode*, bool> vis;

        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;

        int time = 0;

        while (!q.empty()) {

            int size = q.size();
            bool spread = false;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis[node->left]) {
                    vis[node->left] = true;
                    q.push(node->left);
                    spread = true;
                }

                if (node->right && !vis[node->right]) {
                    vis[node->right] = true;
                    q.push(node->right);
                    spread = true;
                }

                if (parent[node] && !vis[parent[node]]) {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                    spread = true;
                }
            }

            if (spread)
                time++;
        }

        return time;
    }
};
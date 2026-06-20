class Solution {
public:
    int findLeftHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->left;
        }
        return h;
    }

    int findRightHeight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
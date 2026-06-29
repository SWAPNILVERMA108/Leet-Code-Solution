class Solution {
public:

    void inorder(TreeNode* root, vector<int>& nums) {

        if (root == nullptr)
            return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    vector<vector<int>> closestNodes(TreeNode* root,
                                     vector<int>& queries) {

        vector<int> nums;

        inorder(root, nums);

        vector<vector<int>> ans;

        for (int q : queries) {

            int floor = -1;
            int ceil = -1;

            auto lb = lower_bound(nums.begin(), nums.end(), q);

            if (lb != nums.end())
                ceil = *lb;

            auto ub = upper_bound(nums.begin(), nums.end(), q);

            if (ub != nums.begin()) {
                ub--;
                floor = *ub;
            }

            ans.push_back({floor, ceil});
        }

        return ans;
    }
};
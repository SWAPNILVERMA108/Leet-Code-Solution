class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* curr = root;

        while(curr){

            if(curr->left == nullptr){

                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{

                TreeNode* pred = curr->left;

                while(pred->right && pred->right != curr){
                    pred = pred->right;
                }

                if(pred->right == nullptr){

                    ans.push_back(curr->val);  // Visit BEFORE going left
                    pred->right = curr;
                    curr = curr->left;
                }
                else{

                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};
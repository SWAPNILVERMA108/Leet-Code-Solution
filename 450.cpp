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

    TreeNode* successor(TreeNode* root){
        root = root->right;
        while(root->left){
            root = root->left;

        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(key<root->val){
            root->left = deleteNode(root->left,key);

        }
        else if(key>root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left==nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->right == nullptr){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* succ = successor(root);
            root->val =succ->val;
            root->right = deleteNode(root->right,succ->val);
        }
        return root;
        
    }
};
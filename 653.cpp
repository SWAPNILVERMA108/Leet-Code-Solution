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
    void inorder(TreeNode* root,vector<int> & arr){
        if(root==nullptr){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        int i=0;
        int j=arr.size()-1;

        while(i<j){
            int sum = arr[i]+arr[j];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
            
        
        }
        return false;
        
    }
};
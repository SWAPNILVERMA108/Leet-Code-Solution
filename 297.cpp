/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preOrder(TreeNode* root,string &s){
        if(root==nullptr){
            s = s+"N,";
            return;
        }
       s.append(to_string(root->val));
       s.push_back(',');
        preOrder(root->left,s);
        preOrder(root->right,s);


    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preOrder(root,s);
        return s;
        
    }

    TreeNode* inString(vector<string> & nodes,int & idx){
        if(nodes[idx]=="N"){
            idx++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(nodes[idx++]));
        root->left  =inString(nodes,idx);
        root->right = inString(nodes,idx);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        for(char ch: data){
            if(ch==','){
                nodes.push_back(temp);
                temp.clear();
            }
            else{
                temp +=ch;
                
            }
        }
        int idx =0;
        return inString(nodes,idx);


        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
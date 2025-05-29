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
    int height(TreeNode* root, bool& balanced){
        
        if( root == NULL){
            return 0;
        }

        int l_height = height(root->left, balanced);
        int r_height = height(root->right, balanced);

        if(((l_height - r_height) > 1) || ((l_height - r_height) < -1))
        {
            balanced = false;
        }

        return max(l_height, r_height) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        height(root, isBalanced);

        return isBalanced;
    }
};
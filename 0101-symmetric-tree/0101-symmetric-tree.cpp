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
    bool helper(TreeNode* leftSub , TreeNode* rightSub){
        if(leftSub == NULL && rightSub == NULL ) return  true;
        if(leftSub == NULL || rightSub == NULL) return false;
        if(leftSub->val != rightSub->val) return false;

        return helper(leftSub->right, rightSub->left) && helper(leftSub->left, rightSub->right);
    }


    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return false;
        
        bool ans = helper(root->left, root->right);
        return ans;
    }
};
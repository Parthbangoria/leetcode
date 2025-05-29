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
    int pathSum(TreeNode* root,int& maxSum){
        if(root == NULL){
            return 0;
        }
        int leftSum = pathSum(root->left, maxSum);
        int rightSum = pathSum(root->right, maxSum);
        
        if(rightSum < 0 && leftSum <0){
            maxSum = max(maxSum,(root->val));
        }
        else if(leftSum <0) {
            maxSum = max(maxSum, (root->val + rightSum));
        }
        else if(rightSum < 0){
            maxSum = max(maxSum, (root->val + leftSum));
        }
        else {
            maxSum = max(maxSum, (root->val + leftSum + rightSum));
        }
        if(max(leftSum, rightSum)>0){
            return root->val + max(leftSum, rightSum);
        }        
        else {
            return root->val;
        }
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        pathSum(root, maxSum);

        return maxSum;
    }
};
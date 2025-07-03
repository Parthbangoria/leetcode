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
    TreeNode* delNode(TreeNode* root){
        if(root->left == NULL && root->right == NULL) return NULL;
        else if (root ->left == NULL){
             return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        else{
            TreeNode* temp = root->left;
            TreeNode* newRoot = root->right;
            TreeNode* newLeft = newRoot;
            while(newLeft->left){
                newLeft = newLeft->left;
            } 
            newLeft->left = temp;
            return newRoot;
        }
        return NULL;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        while(curr != NULL){
            if(curr -> val == key){
                if(root == curr) return delNode(root); 
                if(prev ->left == curr) {
                    prev->left = delNode(curr);
                }
                else{
                    prev->right = delNode(curr);
                }
                break;
            } 
            else if ( curr->val > key){
                prev = curr;
                curr = curr->left;
            }
            else {
                prev = curr;
                curr = curr->right;
            }
        }
        return root;
    }
};
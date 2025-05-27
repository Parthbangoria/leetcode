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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> curr_level;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL){
                ans.push_back(curr_level);
                curr_level.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                else {
                    break;
                }
            }else{
            curr_level.push_back(curr->val);
            if(curr->left){
                q.push(curr->left);
            } 
            if(curr->right){
                q.push(curr->right);
            }
            }
        }
        return ans;
    }
};
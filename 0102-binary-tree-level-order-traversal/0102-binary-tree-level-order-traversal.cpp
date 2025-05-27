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
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(q.size()>0 && q.front() != NULL){
            TreeNode* temp = q.front();
            vector<int> temp_arr;
            while(q.front() != NULL){
                TreeNode* temp = q.front();
                q.pop();
                temp_arr.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                } 
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(temp_arr);
            q.pop();
            q.push(NULL);
        }
        return ans;
    }
};
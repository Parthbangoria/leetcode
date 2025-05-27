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
        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty()){
            vector<int> curr_level;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();
                curr_level.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }               
            }
            ans.push_back(curr_level);
        }
        return ans;
    }
};
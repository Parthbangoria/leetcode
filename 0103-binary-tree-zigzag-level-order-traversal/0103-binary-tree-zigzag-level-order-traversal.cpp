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
    void levelOrder( TreeNode* root, vector<vector<int>>& ans){
        if(root == NULL){
            return;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        bool ltor = true;
        while(q.size()> 0){
            int size = q.size();
            if(ltor == true){
                vector<int> curr_values1;
                for(int i = 0; i<size; i++){
                    TreeNode* temp = q.front();
                    q.pop_front();
                    curr_values1.push_back(temp->val);
                    if(temp->left){
                        q.push_back(temp->left);
                    }
                    if(temp->right){
                        q.push_back(temp->right);
                    }
                }
                ans.push_back(curr_values1);
                ltor = false;
            }
            else{
                vector<int> curr_values2;
                for(int i = 0; i<size; i++){
                    TreeNode* temp = q.back();
                    curr_values2.push_back(temp->val);
                    q.pop_back();
                    if(temp->right){
                        q.push_front(temp->right);
                    }
                    if(temp->left){
                        q.push_front(temp->left);
                    }
                }
                ans.push_back(curr_values2);
                ltor = true;
            }
        }
    }


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrder(root, ans);
        return ans;
    }
};
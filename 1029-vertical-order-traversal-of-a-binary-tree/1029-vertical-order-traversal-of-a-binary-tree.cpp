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
    void helper(TreeNode* root, map<int, map<int, multiset<int>>>& m){
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        while(q.size()>0){
            int size = q.size();
            for(int j=0; j<size; j++){
                auto temp = q.front(); 
                q.pop();
                m[temp.second.first][temp.second.second].insert(temp.first->val);

                if(temp.first->left){
                    q.push({temp.first->left,{ temp.second.first - 1, temp.second.second + 1}});
                }
                if(temp.first ->right){
                    q.push({temp.first->right, {temp.second.first + 1, temp.second.second + 1}});
                }
            }
        }
   }


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        vector<vector<int>> ans;
        helper(root, m);

        map<int ,vector<int>> mm;

    for (auto& [x, levelMap] : m) {          // x = vertical
        vector<int> col;
        for (auto& [y, nodes] : levelMap) {  
            col.insert(col.end(), nodes.begin(), nodes.end());
        }
        ans.push_back(col);
    }    
        return ans;
    }
};
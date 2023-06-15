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
    int maxLevelSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        int sum = INT_MIN;
        int level = 0;

        while(!q.empty()){
            int sz = q.size();
            int tmp = 0;
            level++;
            for(int i=0; i<sz; i++){
                auto curr = q.front();
                q.pop();
                tmp += curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

            if(tmp > sum){
                sum = tmp;
                ans = level;
            }
        }
        return ans;
    }
};

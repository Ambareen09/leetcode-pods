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
        int solve(TreeNode* root, bool isleft, int len){
            
        if(!root) return 0;

        int lh = solve(root->left, true, isleft?1:len+1); 
        int rh = solve(root->right, false, isleft?len+1:1); 

        return max(len,max(lh,rh));
    }

    int longestZigZag(TreeNode* root) {
        
        if(!root) return 0;

        int lh = solve(root->left,true,1);
        int rh = solve(root->right,false,1);

        return max(lh,rh);
        
    }
};
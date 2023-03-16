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
    TreeNode* f(vector<int>& in,int is, int ie, vector<int>& post, int ps, int pe, unordered_map<int, int>&mp){
        if(ps>pe or is>ie) return NULL;
        
        TreeNode* root = new TreeNode(post[pe]);
        int inRoot = mp[post[pe]];
        int numsLeft = inRoot - is;
        
        root->left = f(in, is, inRoot-1, post, ps, ps+numsLeft-1, mp);
        root->right = f(in, inRoot+1, ie, post, ps+numsLeft, pe-1, mp);
        
        return root;
        
    }
    
    
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        if(in.size() != post.size()) return NULL;
        unordered_map<int, int> mp;
        
        for(int i=0;i<in.size();i++) mp[in[i]] = i;
        
        return f(in, 0, in.size()-1, post, 0, post.size()-1, mp);
    }
};
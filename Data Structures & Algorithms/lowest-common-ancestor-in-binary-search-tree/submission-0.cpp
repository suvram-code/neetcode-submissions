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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pv=p->val;
        int qv=q->val;
        TreeNode* r=root;
        while(r){
            if(pv==r->val || qv==r->val) return r;

            if((r->val-pv)*(r->val-qv) <0) return r;
            else r= (pv<r->val) ? r->left : r->right;
        }

    }
};

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
    bool isValidBST(TreeNode* root) {

        //bas ecase
        if(!root) return true;

        bool left= (root->left) ? isValidBST(root->left) : true;
        bool right=(root->right) ? isValidBST(root->right) : true;

        bool ls=true;

        if(left && root->left){
            TreeNode* l=root->left;
            while(l && l->right){
                l=l->right;
            }

            if(l->val < root->val) ls=true;
            else ls=false; 
        }

        bool rs=true;
        if(right && root->right){
            TreeNode* r=root->right;
            while(r && r->left){
                r=r->left;
            }
            if(root->val < r->val) rs=true;
            else rs=false;
        }

        if (left && right && ls && rs) return true;
        else return false;
    }
};

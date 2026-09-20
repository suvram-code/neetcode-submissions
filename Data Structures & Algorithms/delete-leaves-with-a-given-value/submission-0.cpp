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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* jp=root;
        stack<TreeNode*> d;

        while(!s.empty()){
            TreeNode* r=s.top();

            if(jp==r->left){
                
                if(!d.empty() && d.top()==r->left){
                    r->left=nullptr; //parent of  a deletd node
                    if(r->val==target && !r->right){
                        //this also becomes a target leaf
                        d.push(r); 
                    }
                }

                if(r->right) s.push(r->right);
                else {
                    jp=r;
                    s.pop();
                }
            }else if (jp==r->right){
                if(!d.empty() && d.top()==r->right){
                    r->right=nullptr;
                    if(r->val==target && !r->left) {
                        d.push(r); //also a target leaf;
                    }
                }
                jp=r;
                s.pop();
            }
            else{
                if(r->left) s.push(r->left);
                else if (r->right) s.push(r->right);
                else { //leaf

                    if(r->val==target){
                        d.push(r);
                    }

                    jp=r;
                    s.pop();
                }
            }
        }

        TreeNode* ans=root;
        while(!d.empty()){
            TreeNode* r=d.top();
            d.pop();
            if(r==root) ans=nullptr;
            delete r;
        }
        return ans;
    }
};
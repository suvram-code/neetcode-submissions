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
    int goodNodes(TreeNode* root) {
        
        int ans=0;
        std::stack<TreeNode*> s;

        s.push(root);
        TreeNode* r;

        std::stack<int> max; //max paths in a path
        max.push(root->val);
        TreeNode* jp=root;

        while(!s.empty()){
            r=s.top();
            
            if( r->left!=jp && r->right!=jp){
                //juste netered
                
                if(r->val >= max.top() ){
                    ans++;
                    max.push(r->val);
                }

                if(r->left) s.push(r->left);
                else if(r->right) s.push(r->right);
                else {
                    //pop it, go up
                    jp=r;
                    s.pop();
                    if(r->val ==max.top()) max.pop();
                   
                }
            }else if(jp==r->left){
                //entered from right side
                if(r->right) s.push(r->right);
                else{
                    //pop it, go up
                    jp=r;
                    s.pop();
                    if(r->val ==max.top()) max.pop();
                    
                }
            }else if(jp==r->right){
                jp=r;
                if(r->val ==max.top()) max.pop();
                s.pop();
                
            }
        }

        return ans;

    }
};

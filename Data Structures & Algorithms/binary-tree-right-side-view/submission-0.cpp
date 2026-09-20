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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        std::stack<TreeNode*> s;
        TreeNode* r=root;
        s.push(r);
        TreeNode* jp=root; //just popped treendoe
        int depth=0;
        int size=0;
        
        
        while(!s.empty()){
            r=s.top();
            
            if( r->left!=jp && r->right!=jp){
                //juste netered
                 depth++;
                 if(depth>size){
                    v.push_back(r->val);
                    size++;
                 }else  v[depth-1]=r->val;
                

                if(r->left) s.push(r->left);
                else if(r->right) s.push(r->right);
                else {
                    //pop it, go up
                    jp=r;
                    s.pop();
                    depth--;
                }
            }else if(jp==r->left){
                //entered from right side
                if(r->right) s.push(r->right);
                else{
                    //pop it, go up
                    jp=r;
                    s.pop();
                    depth--;
                }
            }else if(jp==r->right){
                jp=r;
                s.pop();
                depth--;
            }
        }

        return v;
    }
};

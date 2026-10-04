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
    bool isCompleteTree(TreeNode* root) {
        
        int leftDepth=0;
        TreeNode* l=root;
        while(l){
            leftDepth++;
            l=l->left;
        }


        stack<TreeNode*> s;
        TreeNode* jr=root;
        int maxDepth=0;
        int depth=0;
        s.push(root);
        while(!s.empty()){
            TreeNode* r=s.top();
            if(jr==r->right){
                if(r->left){
                    s.push(r->left);
                }else{
                    if(depth<maxDepth || depth<leftDepth-1) return false;
                    jr=r;
                    s.pop();
                    depth--;
                }
            }else if(jr==r->left){
                jr=r;
                s.pop();
                depth--;
            }else{
                depth++;
                if(depth>maxDepth) maxDepth=depth;
                if(r->right){
                    s.push(r->right);
                }
                else{
                    if(depth<maxDepth || depth<leftDepth-1) return false;
                    else if(r->left){
                        s.push(r->left);
                    }else{
                        jr=r;
                        s.pop();
                        depth--;
                    }
                }
            }
        }

        return true;
    }
};
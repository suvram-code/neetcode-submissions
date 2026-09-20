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
    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*> s;
        s.push(root);
        TreeNode* curr=root;
        while(curr && curr->left){
            curr=curr->left;
            s.push(curr);
            

        }

        for(int i=1; i<=k-1;i++){

            if(curr->right){
                curr=curr->right;
                s.push(curr);
                while(curr && curr->left){
                    curr=curr->left;
                    s.push(curr);
                }
            }else{
                //TreeNode* removed=curr;
                s.pop();
                while(!s.empty() && curr!=s.top()->left){
                    curr=s.top();
                    s.pop();
                }
                curr=s.top();
            }

        }

        return curr->val;


    }
};

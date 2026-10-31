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
private:
    int dfsHeight(TreeNode* root) {
        
        if(root == NULL){
            return 0; // height of empty tree
        }

        int lh = dfsHeight(root -> left);
        if(lh == -1){
            return -1; // left subtree unbalanced
        }

        int rh = dfsHeight(root -> right);
        if(rh == -1){
            return -1; // right subtree unbalanced
        }

        if(abs(lh - rh) > 1){
            return -1; // current node unbalanced
        }

        return 1 + max(lh , rh); // return height
    }

public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }
};

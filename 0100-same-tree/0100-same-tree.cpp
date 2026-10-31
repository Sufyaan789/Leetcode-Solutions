/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        // base case
        if (r1 == NULL && r2 == NULL)
            return true;
        if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
            return false;

        bool leftAns = false;
        bool rightAns = false;
        if (r1->val == r2->val) {
            leftAns = isSameTree(r1->left, r2->left);
            rightAns = isSameTree(r1->right, r2->right);
        }

        return (leftAns && rightAns);
    }
};
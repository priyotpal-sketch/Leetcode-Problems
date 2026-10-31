// time complexity will be O(n) in worst case if we have to visit each and every node and space comlexity will be O(h) where h is the height of recursion stack 
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        targetSum -= root->val;

        if (root->left == NULL && root->right == NULL) {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) ||
               hasPathSum(root->right, targetSum);
    }
};
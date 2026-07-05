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
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if(start > end) {
            return NULL;
        }

        // root from preorder
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        // if leaf node
        if(start == end) {
            return root;
        }

        // find root in inorder
        int pos;
        for(int i = start; i <= end; i++) {
            if(inorder[i] == root->val) {
                pos = i;
                break;
            }
        }

        // build left subtree
        root->left = build(preorder, inorder, start, pos - 1);

        // build right subtree
        root->right = build(preorder, inorder, pos + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
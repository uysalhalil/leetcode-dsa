#include "TreeNode.h"

class Solution {
   public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;

        if (root->val == val) return root;

        return root->val > val ? searchBST(root->left, val)
                               : searchBST(root->right, val);
    }
};
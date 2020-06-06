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
    TreeNode* invertTree(TreeNode* root) {
        #include <stddef.h>
            //節點為null或沒有子節點，不用反轉，終止遞迴
    if( root == NULL || (root -> right == NULL && root -> left == NULL)){
        return root;    
    }
    // 左節點為本來的右節點反轉，右節點為本來的左節點反轉
    TreeNode*temp = root -> left;
    root->left = invertTree(root -> right);
    root->right = invertTree(temp);

    return root;
    }
};
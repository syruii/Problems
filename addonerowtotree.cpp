//
// Created by Syrup on 6/04/2018.
// https://leetcode.com/problems/add-one-row-to-tree/description/
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRowDepth(TreeNode* node, int v, int d, int cd) {
        if (cd == d - 1) {
            TreeNode* newLeft = new TreeNode(v);
            TreeNode* newRight = new TreeNode(v);
            newLeft->left = node->left;
            newRight->right = node->right;
            node->left = newLeft;
            node->right = newRight;
        } else {
            // go deeper
            if (node->left != NULL) {
                addOneRowDepth(node->left, v, d, cd+1);
            }
            if (node->right != NULL) {
                addOneRowDepth(node->right, v, d, cd+1);
            }
        }
        return node;
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        if (d == 2) {
            TreeNode* newLeft = new TreeNode(v);
            TreeNode* newRight = new TreeNode(v);
            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;
            return root;
        }
        if (root->left != NULL) {
            addOneRowDepth(root->left, v, d, 2);
        }
        if (root->right != NULL) {
            addOneRowDepth(root->right, v, d, 2);
        }
        return root;
    }
};

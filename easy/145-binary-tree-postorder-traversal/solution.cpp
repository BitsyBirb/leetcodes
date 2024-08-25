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
#include <vector>
#include <string>

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // Just return a vector with its data in it inserted into the end of the list.
        vector<int> this_tree;
        if(root == nullptr) return this_tree;
        // Visit left and append its result
        vector<int> sub_tree = postorderTraversal(root->left);
        this_tree.insert(this_tree.end(), sub_tree.begin(), sub_tree.end());
        sub_tree = postorderTraversal(root->right);
        this_tree.insert(this_tree.end(), sub_tree.begin(), sub_tree.end());
        // Now append this data to it
        this_tree.push_back(root->val);
        return this_tree;
    }
};
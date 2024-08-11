//
// Created by Admin on 8/11/2024.
//

#include "tree_create.h"


int maxValue(TreeNode* current, int updated_max) {
    if (!current) return 0;
    int current_mx = max(updated_max, current->val);
    int mx_left = maxValue(current->left, max(updated_max, current->val));
    int mx_right = maxValue(current->right, max(updated_max, current->val));
    return max(max(mx_left, mx_right), current_mx);
}

int maxValue(TreeNode* root) {
    return maxValue(root, root->val);
}

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return max(left_depth, right_depth) + 1;
}

bool hasPathSum(TreeNode* current, int targetSum, int updated_sum) {
    //base case
    if (!current) return 0;

    //so far sum
    updated_sum += current->val;

    if (!current->right && !current->left)
        return updated_sum == targetSum;

    return hasPathSum(current->left, targetSum, updated_sum) || hasPathSum(current->right, targetSum, updated_sum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    return hasPathSum(root, targetSum, 0);
}

int sumOfLeftLeaves(TreeNode* current, int updated_sum) {
    if (!current) return 0;

}

int sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftLeaves(root, 0);
}

int main() {

    BinaryTree tree(5);
    tree.add( { 4, 11, 7 }, { 'L', 'L', 'L' });
    tree.add( { 4, 11, 2 }, {  'L', 'L', 'R' });
    tree.add( { 8, 4, 1 }, { 'R', 'R', 'R'});
    tree.add({8, 13}, {'R', 'L'});

    cout << hasPathSum(tree.root, 22);
    //tree.print_inorder();
    // 7 4 8 2 5 9 1 3 10 6

    return 0;

    return 0;
}
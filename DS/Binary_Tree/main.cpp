//
// Created by Admin on 8/11/2024.
//

#include <cmath>
#include <queue>
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

bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;
    if (isLeaf(root->left))
        sum += root->left->val;

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int sum_tree(TreeNode* root, int updated_sum = 0) {
    if (!root) return 0;
    int sum = root->val;
    sum += sum_tree(root->left);
    sum += sum_tree(root->right);
    return sum;
}

bool is_full_tree(TreeNode* root) {
    if (!root) return false;
    if (isLeaf(root)) return true;
    if ( (!root->left && root->right) || (!root->right && root->left) ) return false;
    return is_full_tree(root->left) &&
            is_full_tree(root->right);
}

int count_nodes(TreeNode* root) {
    if (!root) return 0;
    return count_nodes(root->left) +
            count_nodes(root->right) + 1;
}

bool is_perfect_tree(TreeNode* root) {
    if (!root) return true;

    //check left and right children
    if (count_nodes(root->left) != count_nodes(root->right)) return false;

    return is_perfect_tree(root->left) &&
            is_perfect_tree(root->right);
}

bool is_perfect_tree_v2(TreeNode* root, int level) {
    //all leaves must be in the same level (last level)
    if (isLeaf(root))
        return level == 0;
    //check one child
    if ( (!root->left && root->right) || (!root->right && root->left) ) return false;

    return is_perfect_tree_v2(root->left, level - 1) &&
            is_perfect_tree_v2(root->right, level - 1);
}

bool is_perfect_tree_v2(TreeNode* root) {
    int level = maxDepth(root) - 1;
    return is_perfect_tree_v2(root, level);
}

//optimum solution >> just count left and right and compare
pair<bool, int> is_perfect_tree_v3(TreeNode* root) {
    //empty tree
    if (!root) return {false, 0};

    //in case of leaf node
    if (!root->left && !root->right) return {true, 1};

    auto left = is_perfect_tree_v3(root->left);
    auto right = is_perfect_tree_v3(root->right);

    bool perfect = left.first && right.first && (left.second == right.second);

    return {perfect, left.second + right.second + 1};
}

int updated_mx_diameter;
int hight_of_tree(TreeNode* root) {
    if (!root) return 0;

    auto left = hight_of_tree(root->left);
    auto right = hight_of_tree(root->right);

    updated_mx_diameter = max(updated_mx_diameter, left + right);

    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    hight_of_tree(root);
    return updated_mx_diameter;
}

void level_order_traversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        cout << "level:" << level << "\n";
        while (sz--) {
            TreeNode* cur_top = q.front();
            cout << cur_top->val << " ";
            q.pop();

            if (cur_top->left)
                q.push(cur_top->left);
            if (cur_top->right)
                q.push(cur_top->right);
        }
        level++;
        cout << "\n";
    }
}

int main() {

    BinaryTree tree(1);
    tree.add( { 2, 4 }, { 'L', 'L'});
    tree.add( { 2, 5 }, {  'L', 'R' });
    tree.add( { 3, 7}, { 'R', 'R'});
    tree.add({3, 6}, {'R', 'L'});


    return 0;
}
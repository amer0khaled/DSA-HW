#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>

#include "tree_create.h"'
using namespace std;


bool is_leaf(TreeNode* root) {
    return root && !root->left && !root->right;
}

TreeNode* get_minimum(TreeNode* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* get_maximum(TreeNode* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size() - 1);
}

void print_inorder(TreeNode* current) {
    if (!current)
        return;
    print_inorder(current->left);
    cout << current->val << " ";
    print_inorder(current->right);
}

void print_preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    print_preorder(root->left);
    print_preorder(root->right);
}

vector<vector<int>> v;
vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) return {};
    queue<TreeNode*> q;
    vector<int> level;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* cur = q.front();
            level.push_back(cur->val);
            q.pop();

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        v.push_back(level);
    }
    return v;
}

bool find_chain(TreeNode* root, int target, vector<TreeNode*> &ancestors) {
    ancestors.push_back(root);
    if (root->val == target) return true;
    if (root->val > target) return find_chain(root->left, target, ancestors);
    return root->right && find_chain(root->right, target, ancestors);
}

TreeNode* get_next(vector<TreeNode*> &ancestors) {
    if (ancestors.empty()) return nullptr;
    TreeNode* cur = ancestors.back();
    ancestors.pop_back();
    return cur;
}

pair<bool, int> find_successor(TreeNode* root, int target) {
    vector<TreeNode*> ancestors;

    //make chain
    if (!find_chain(root, target, ancestors)) //target not exist
        return make_pair(false, -1);

    //successor min number on the right of me
    TreeNode* child = get_next(ancestors);
    if (child->right)
        return make_pair(true, get_minimum(child->right)->val);

    //climbing chain
    TreeNode* parent = get_next(ancestors);
    while (parent && parent->right == child)
        child = parent, parent = get_next(ancestors);

    if (parent) return make_pair(true, parent->val);
    return make_pair(false, -1);
}

TreeNode* find_node(TreeNode* root, int target) {
    if (!root) return nullptr;
    if (root->val == target) return root;
    if (root->val > target) return find_node(root->left, target);
    if (root->val < target) return find_node(root->right, target);
}

TreeNode* delete_node(TreeNode* root, int target) {
    if (!root) return nullptr;
    if (root->val > target)
        root->left = delete_node(root->left, target);
    else if (root->val < target)
        root->right = delete_node(root->right, target);
    else {
        TreeNode* tmp = root;
        if (is_leaf(root))
            root = nullptr;
        else if (!root->left)
            root = root->right;
        else if (!root->right)
            root = root->left;
        else {
            TreeNode* mn = get_minimum(root->right);
            root->val = mn->val;
            root->right = delete_node(root->right, mn->val);
            tmp = nullptr;
        }

        if (tmp) delete tmp;
    }
    return root;
}

int main() {

    BinaryTree tree(10);
    tree.add({8, 4}, {'L', 'L'});
    tree.add({30, 70}, {'R', 'R'});
    tree.add({8, 9}, {'L', 'R'});
    tree.add({30, 20}, {'R', 'L'});

    print_inorder(tree.root);
    cout << endl;

    auto t= delete_node(tree.root, 30);
    
    print_inorder(t);

    return 0;
}

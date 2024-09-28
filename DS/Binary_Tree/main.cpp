//
// Created by Admin on 8/11/2024.
//

#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include "tree_create.h"
#include <climits>

int maxValue(TreeNode *current, int updated_max)
{
    if (!current)
        return 0;
    int current_mx = max(updated_max, current->val);
    int mx_left = maxValue(current->left, max(updated_max, current->val));
    int mx_right = maxValue(current->right, max(updated_max, current->val));
    return max(max(mx_left, mx_right), current_mx);
}

int maxValue(TreeNode *root)
{
    return maxValue(root, root->val);
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return max(left_depth, right_depth) + 1;
}

bool hasPathSum(TreeNode *current, int targetSum, int updated_sum)
{
    // base case
    if (!current)
        return 0;

    // so far sum
    updated_sum += current->val;

    if (!current->right && !current->left)
        return updated_sum == targetSum;

    return hasPathSum(current->left, targetSum, updated_sum) || hasPathSum(current->right, targetSum, updated_sum);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    return hasPathSum(root, targetSum, 0);
}

bool isLeaf(TreeNode *node)
{
    return node && !node->left && !node->right;
}

int sumOfLeftLeaves(TreeNode *root)
{
    if (!root)
        return 0;

    int sum = 0;
    if (isLeaf(root->left))
        sum += root->left->val;

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int sum_tree(TreeNode *root, int updated_sum = 0)
{
    if (!root)
        return 0;
    int sum = root->val;
    sum += sum_tree(root->left);
    sum += sum_tree(root->right);
    return sum;
}

bool is_full_tree(TreeNode *root)
{
    if (!root)
        return false;
    if (isLeaf(root))
        return true;
    if ((!root->left && root->right) || (!root->right && root->left))
        return false;
    return is_full_tree(root->left) &&
           is_full_tree(root->right);
}

int count_nodes(TreeNode *root)
{
    if (!root)
        return 0;
    return count_nodes(root->left) +
           count_nodes(root->right) + 1;
}

bool is_perfect_tree(TreeNode *root)
{
    if (!root)
        return true;

    // check left and right children
    if (count_nodes(root->left) != count_nodes(root->right))
        return false;

    return is_perfect_tree(root->left) &&
           is_perfect_tree(root->right);
}

bool is_perfect_tree_v2(TreeNode *root, int level)
{
    // all leaves must be in the same level (last level)
    if (isLeaf(root))
        return level == 0;
    // check one child
    if ((!root->left && root->right) || (!root->right && root->left))
        return false;

    return is_perfect_tree_v2(root->left, level - 1) &&
           is_perfect_tree_v2(root->right, level - 1);
}

bool is_perfect_tree_v2(TreeNode *root)
{
    int level = maxDepth(root) - 1;
    return is_perfect_tree_v2(root, level);
}

// optimum solution >> just count left and right and compare
pair<bool, int> is_perfect_tree_v3(TreeNode *root)
{
    // empty tree
    if (!root)
        return {false, 0};

    // in case of leaf node
    if (!root->left && !root->right)
        return {true, 1};

    auto left = is_perfect_tree_v3(root->left);
    auto right = is_perfect_tree_v3(root->right);

    bool perfect = left.first && right.first && (left.second == right.second);

    return {perfect, left.second + right.second + 1};
}

int updated_mx_diameter;
int hight_of_tree(TreeNode *root)
{
    if (!root)
        return 0;

    auto left = hight_of_tree(root->left);
    auto right = hight_of_tree(root->right);

    updated_mx_diameter = max(updated_mx_diameter, left + right);

    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    hight_of_tree(root);
    return updated_mx_diameter;
}

void level_order_traversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int sz = q.size();
        cout << "level:" << level << "\n";
        while (sz--)
        {
            TreeNode *cur_top = q.front();
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

int goodNodes(TreeNode* current, int updated_max) {
    if (!current) return 0;
    int am_a_good = current->val >= updated_max;
    int good_left = goodNodes(current->left, max(current->val, updated_max));
    int good_right = goodNodes(current->right, max(current->val, updated_max));
    return am_a_good + good_left + good_right;
}

int goodNodes(TreeNode* root) {
    if (!root) return 0;
    return goodNodes(root, root->val);
}

int maxNodeOfTree(TreeNode* root) {
    if (!root) return INT_MIN;
    int mx_left = maxNodeOfTree(root->left);
    int mx_right = maxNodeOfTree(root->right);
    return max(max(mx_left, mx_right), root->val);
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    deque<TreeNode *> q;
    q.push_front(root);
    int level = 0;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> current_level;
        TreeNode *cur{};
        while (sz--)
        {
            if (level & 1)
            {
                cur = q.back();
                // cout << cur->val << " ";
                current_level.push_back(cur->val);
                q.pop_back();
                if (cur->right)
                    q.push_front(cur->right);
                if (cur->left)
                    q.push_front(cur->left);
            }
            else
            {
                cur = q.front();
                // cout << cur->val << " ";
                current_level.push_back(cur->val);
                q.pop_front();
                if (cur->left)
                    q.push_back(cur->left);
                if (cur->right)
                    q.push_back(cur->right);
            }
        }
        result.push_back(current_level);
        ++level;
    }
    return result;
}

string paransizing_tree(TreeNode *root)
{
    if (!root)
        return "";

    string result = "(" + to_string(root->val);

    if (root->left)
        result += paransizing_tree(root->left);
    else
        result += "()";

    if (root->right)
        result += paransizing_tree(root->right);
    else
        result += "()";

    result += ")";

    return result;
}

string canonicalizing_tree(TreeNode *root)
{
    if (!root)
        return "()";
    string result = "(" + to_string(root->val);

    vector<string> arrange;

    if (left)
        arrange.push_back(canonicalizing_tree(root->left));
    else
        arrange.push_back("()");

    if (right)
        arrange.push_back(canonicalizing_tree(root->right));
    else
        arrange.push_back("()");

    sort(arrange.begin(), arrange.end());
    for (int i = 0; i < arrange.size(); ++i)
    {
        result += arrange[i];
    }

    result += ")";

    return result;
}

// leetcode problem

string serialization(TreeNode *root)
{
    if (!root)
        return "()";

    // serialization
    string s = "";
    s += "(" + to_string(root->val);

    vector<string> v;

    if (left)
        v.push_back(serialization(root->left));
    else
        v.push_back("()");

    if (right)
        v.push_back(serialization(root->right));
    else
        v.push_back("()");

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
        s += v[i];

    s += ")";

    return s;

}

bool isSymmetric(TreeNode *root)
{
    string left = serialization(root->left);
    string right = serialization(root->right);

    return left == right;
}

bool level_serialization(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    bool no_more_nodes = false;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->left) {
                if (no_more_nodes)
                    return false;
                q.push(cur->left);
            }
            else
                no_more_nodes = true;

            if (cur->right) {
                if (no_more_nodes)
                    return false;
                q.push(cur->right);
            }
            else
                no_more_nodes = true;
        }
    }
    return true;
}

bool isCompleteTree(TreeNode* root) {
    if (!root) return false;
    return level_serialization(root);
}


unordered_map<string, int> freq;
vector<TreeNode*> result;
string serializationTree(TreeNode* root) {
    if (!root) return "()";
    string s;
    s = "(" + to_string(root->val);

    if (root->left)
        s += serializationTree(root->left);
    else
        s += "()";
    if (root->right)
        s += serializationTree(root->right);
    else
        s += "()";
    s += ")";

    if (freq[s]++ == 1)
        result.push_back(root);

    return s;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    if (!root) return {};

    serializationTree(root);

    return result;
}


int main()
{

    BinaryTree tree(1);

    /*
    tree.add( { 2, 4 }, { 'L', 'L'});
    tree.add( { 2, 5 }, {  'L', 'R' });
    tree.add( { 3, 7}, { 'R', 'R'});
    tree.add({3, 6}, {'R', 'L'});
    */

    tree.add({2}, {'L'});
    tree.add({3}, {'R'});
    auto res = canonicalizing_tree(tree.root);

    cout << res << endl;

    return 0;
}

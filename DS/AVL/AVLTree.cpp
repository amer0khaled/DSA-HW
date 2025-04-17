//
// Created by amer kahled on 10/28/24.
//


#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
using namespace std;

class AVLTree {

private:
    struct AVLNode {
        int val {};
        int height {};
        AVLNode *left {};
        AVLNode *right {};

        AVLNode(int data) : val(data) {}

        int child_height(AVLNode *node) {
            if (!node) return -1;
            return node->height;
        }

        int update_height() {
            return 1 + max(child_height(left), child_height(right));
        }

        int balance_factor() {
            return child_height(left) - child_height(right);
        }

    };


    AVLNode* root {};

    /*****************************************/

    AVLNode* right_rotation(AVLNode* node) {
        AVLNode* temp = node->left;
        node->left = temp->right;
        temp->right = node;

        node->update_height();
        temp->update_height();

        return temp;
    }

    AVLNode* left_rotation(AVLNode* node) {
        AVLNode* temp = node->right;
        node->right = temp->left;
        temp->left = node;

        node->height =  node->update_height();
        temp->height = temp->update_height();

        return temp;
    }


    AVLNode* node_balancing(AVLNode *node) {
        /** left hight is longer than right by 2 */
        if (node->balance_factor() == 2) {
            if (node->left->balance_factor() == -1)
                node->left = left_rotation(node->left);

            node = right_rotation(node);
        }
        /** right hight is longer than left by 2 */
        else if (node->balance_factor() == -2) {
            if (node->right->balance_factor() == 1)
                node->right = right_rotation(node->right);

            node = left_rotation(node);
        }
        return node;
    }

    AVLNode* insert_node(int target, AVLNode* node) {
        if (!node) 
            return new AVLNode(target);
        
        if (node->val > target) 
            node->left = insert_node(target, node->left);

        else if (node->val < target) 
            node->right = insert_node(target, node->right);

        node->height = node->update_height();
        return node_balancing(node);
    }

    bool is_bst(AVLNode* node) {
        
    }

    bool is_leaf(AVLNode* node) {
        return node && !node->left && !node->right;
    }

    void clear(AVLNode* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:

    void insert_value(int val) {
        if (!root) {
            root = new AVLNode(val);
        }
        else {
            root = insert_node(val, root);
        }
    }

    void print_inorder(AVLNode* node) {
        if (!node) return;
        print_inorder(node->left);
        cout << node->val << " ";
        print_inorder(node->right);
    }

    void level_order_traversal() {
        if (!root) return;
        queue<AVLNode*> dq;

        dq.push(root);
        int level = 0;
        while (!dq.empty()) {
            int sz = dq.size();
            for (int i = 0; i < sz; i++) {
                AVLNode* node = dq.front();
                dq.pop();
                cout << node->val << " ";
                if (node->left) dq.push(node->left);
                if (node->right) dq.push(node->right);
            }
            level++;
            cout << "\n";
        }
    }

};

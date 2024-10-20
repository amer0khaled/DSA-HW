#include<iostream>
using namespace std;


class TrieNode {

public:

    static const int MAX_CHILDREN  {26};
    TrieNode* children[MAX_CHILDREN] {};
    bool isLeaf {};

    TrieNode() {
        isLeaf = false;
        for (auto item : children)
            item = nullptr;
    }

};


class Trie {
private:

    TrieNode* root;

public:

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        insert_helper(root, word);
    }

    bool search(string word) {
        return search_helper(root, word);
    }

    bool start_with(string prefix) {
        return start_with_helper(root, prefix);
    }


private:

    void insert_helper(TrieNode* node, string word, int indx = 0) {
        if (indx >= word.size()) {
            node->isLeaf = true;
            return;
        }

        auto pos = word[indx] - 'a';
        if (node->children[pos] == nullptr)
            node->children[pos] = new TrieNode();

        insert_helper(node->children[pos], word, indx + 1);
    }

    bool search_helper(TrieNode* node, string word, int indx = 0) {
        if (indx >= word.size()) return node->isLeaf;

        auto pos = word[indx] - 'a';
        if (node->children[pos] == nullptr)
            return false;

        return search_helper(node->children[pos], word, indx + 1);
    }

    bool start_with_helper(TrieNode* node, string prefix, int indx = 0) {
        if (indx >= prefix.size()) return true;

        auto pos = prefix[indx] - 'a';
        if (node->children[pos] == nullptr)
            return false;

        return start_with_helper(node->children[pos], prefix, indx + 1);
    }

};

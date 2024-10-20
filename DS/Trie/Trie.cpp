//
// Created by Admin on 10/20/2024.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class TrieNode {
private:
    TrieNode* children[26] {};
    bool isLeaf {};
public:


    void setEndOfWord() {
        this->isLeaf = true;
    }

    bool containsKey(char key) {
        auto keyPosition = key - 'a';
        return children[keyPosition] != nullptr;
    }

    void putKey(char key, TrieNode* node) {
        auto keyPosition = key - 'a';
        children[keyPosition] = node;
    }

    TrieNode* getReference(char key) {
        auto keyPosition = key - 'a';
        return children[keyPosition];
    }

    bool isEndOfWord(){
        return isLeaf;
    }

};

class Trie {
private:
    TrieNode* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!node->containsKey(word[i]))
                node->putKey(word[i], new TrieNode());

            // moves to the reference trie
            node = node->getReference(word[i]);
        }

        // marks the end of the word
        node->setEndOfWord();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!node->containsKey(word[i]))
                return false;

            // moves to the reference trie
            node = node->getReference(word[i]);
        }

        // returns if the last node marked as end of the word
        return node->isEndOfWord();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (!node->containsKey(prefix[i]))
                return false;

            // moves to the reference trie
            node = node->getReference(prefix[i]);
        }

        // if the execution reaches here so the prefix exists
        return true;
    }

    // Easy P2
    string first_word_prefix(const string &str) {
        TrieNode* node = root;
        string result = "";

        for (int i = 0; i < str.size(); ++i) {
            if (node->containsKey(str[i])) {
                result += str[i];
                node = node->getReference(str[i]);
            }
            else
                break;
        }
        if (result.empty())
            return str;
        return result;
    }


};

int main() {
    Trie trie;

    trie.insert("xyz");
    trie.insert("xyeA");
    trie.insert("a");
    trie.insert("bc");

    cout << trie.first_word_prefix("bcw");
}
//
// Created by Admin on 10/20/2024.
//

#include <iostream>
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
    int count_prefix {};

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

    void increasePrefix(char key) {
        this->count_prefix++;
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


    /***********************************/

    void insert(string &word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (!node->containsKey(word[i]))
                node->putKey(word[i], new TrieNode());

            // increase key prefix
            node->increasePrefix(word[i]);

            // moves next to the reference trie
            node = node->getReference(word[i]);
        }

        // marks the end of the word
        node->setEndOfWord();
    }

    int countWordsEqualTo(string &word){

    }

    int countWordsStartingWith(string &word){
        // Write your code here.
    }

    void erase(string &word){
        // Write your code here.
    }

};

int main() {



    return 0;
}
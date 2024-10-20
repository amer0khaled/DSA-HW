//
// Created by Admin on 10/17/2024.
//
#include "trie.h"
class Trie {
private:
    static const int MAX_CHAR = 26;
    Trie *child[MAX_CHAR];
    bool isLeaf{};

public:

    // Constructor to initialize the Trie node
    Trie() {
        // set isLeaf flag to false
        isLeaf = false;
        // Set child array to null pointers
        memset(child, 0, sizeof(child));
    }


    // Insert a word into the trie
    void insert(string str, int idx = 0) {
        if (idx == str.size()) {
            isLeaf = true;  // Mark the end of the word
        } else {
            int cur = str[idx] - 'a';  // Calculate index for the character
            if (child[cur] == nullptr)
                child[cur] = new Trie();  // Create a new trie node if necessary

            child[cur]->insert(str, idx + 1);  // Recur for the next character
        }
    }

    // Check if a prefix exists in the trie
    bool search_prefix(string str, int idx = 0) {
        if (idx >= str.size()) {
            return true;  // Prefix covered, return true
        }
        int cur = str[idx] - 'a';
        if (child[cur] == nullptr) {
            return false;  // Path does not exist
        }
        return child[cur]->search_prefix(str, idx + 1);  // Recur for the next character
    }

    // Check if a word exists in the trie
    bool search_word(string str, int idx = 0) {
        if (idx >= str.size()) {
            return isLeaf;  // If end of the word, check if it's a valid word
        }
        int cur = str[idx] - 'a';
        if (child[cur] == nullptr) {
            return false;  // Path does not exist
        }
        return child[cur]->search_word(str, idx + 1);  // Recur for the next character
    }

    // Check if a word exists with one Change in the trie
    bool word_exist_with_1_change(string str) {
        for (int i = 0; i < str.size(); ++i) {
            auto cpy = str[i]; // Save the original character

            // Try replacing the current character with every other character ('a' to 'z')
            for (int ch = 'a'; ch <= 'z'; ++ch) {
                if (ch == str[i]) continue; // Skip if it's the same character
                str[i] = ch; // Replace the character
                if (search_word(str)) return true; // Check if the modified word exists in the trie
            }
            str[i] = cpy; // Restore the original character before trying the next one
        }
        return false; // No word with one change exists
    }

    vector<string> check_query(string str, vector<string>& q) {
        vector<string> res {};

        // Loop over each query string in q
        for (int i = 0; i < q.size(); ++i) {
            int sz = q[i].size();

            // Traverse the main string with a sliding window of query size
            for (int f = 0, l = sz - 1; l < str.size(); ++f, ++l) {
                string found_substring = str.substr(f, sz);

                // If the substring matches the query, add it to the result
                if (found_substring == q[i])
                    res.push_back(found_substring);
            }
        }
        return res;
    }
};
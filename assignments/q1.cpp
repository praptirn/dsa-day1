/*
1. The "Global Autocomplete" System (Tries)
Problem: 
Build a Trie-based system that stores 1 million strings. Implement a
function that returns the top 5 most frequent suggestions for a given prefix.
Complexity Requirement: 
The prefix search must be O(L), where L is the length of
the prefix, regardless of the dictionary size.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> child;
    vector<pair<int,string>> top;
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word, int freq) {
        TrieNode* node = root;

        for(char c : word) {
            if(!node->child[c])
                node->child[c] = new TrieNode();

            node = node->child[c];

            node->top.push_back({freq, word});
            sort(node->top.begin(), node->top.end(),
                 [](auto &a, auto &b){ return a.first > b.first; });

            if(node->top.size() > 5)
                node->top.pop_back();
        }
    }

    vector<string> searchPrefix(string prefix) {
        TrieNode* node = root;

        for(char c : prefix) {
            if(!node->child.count(c))
                return {};
            node = node->child[c];
        }

        vector<string> ans;
        for(auto &p : node->top)
            ans.push_back(p.second);

        return ans;
    }
};

int main() {
    Trie trie;
    int n;

    cout << "Enter number of words: ";
    cin >> n;

    cout << "Enter word and frequency:\n";
    for(int i = 0; i < n; i++) {
        string word;
        int freq;
        cin >> word >> freq;
        trie.insert(word, freq);
    }

    string prefix;
    cout << "\nEnter prefix to search: ";
    cin >> prefix;

    vector<string> suggestions = trie.searchPrefix(prefix);

    if(suggestions.empty()) {
        cout << "No suggestions found.\n";
    } else {
        cout << "Top suggestions:\n";
        for(string word : suggestions)
            cout << word << endl;
    }

    return 0;
}
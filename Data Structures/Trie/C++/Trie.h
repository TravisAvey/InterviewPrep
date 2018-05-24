//
// Created by travis on 5/24/18.
//

#ifndef __TRIE_H__
#define __TRIE_H__

#include <map>

class TrieNode {
private:
    std::map<char, TrieNode> *children;
    bool word;
public:
    TrieNode() {
        children = new std::map<char, TrieNode>();

        word = false;
    }

    TrieNode * getChild(char ch) {
        return (TrieNode *) children->at(ch);
    }

    void putChild(char ch, TrieNode *node) {
        children->insert(ch, *node);
    }

    bool isWord() {
        return word;
    }

    void setWord(bool isWord) {
        word = isWord;
    }
};

class Trie {
private:
    TrieNode *trieRoot;
public:

    Trie() {
        trieRoot = new TrieNode();
    }

    void insert(std::string word) {
        if (word == "" || word == nullptr)
            return;

        TrieNode *current = trieRoot;

        for (int i=0; i<word.length(); i++) {
            char ch = word[i];
            TrieNode *node = current->getChild(ch);

            if (node == NULL) {
                node = new TrieNode();
                node->putChild(ch, node);
            }

            current = node;

        }

        current->setWord(true);

    }

};

#endif //__TRIE_H__

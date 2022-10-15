#include <vector>
#include <string>
#include "TrieNode.h"

class Trie
{
    TrieNode *root;

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
            return true; // root->isTerminal is not used

        int index = word[0] - 'a';
        TrieNode *child = root->children[index];
        if (child == NULL)
            return false;

        return search(child, word.substr(1));
    }

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    bool search(string word)
    {
        return search(root, word);
    }

    bool patternMatching(vector<string> vect, string pattern)
    {

        for (int i = 0; i < vect.size(); i++)
        {
            // inserting all suffixes of a word
            while (vect[i].size() != 0)
            {
                insertWord(vect[i]);
                vect[i] = vect[i].substr(1);
            }
        }

        // searching pattern
        return search(pattern);
    }
};
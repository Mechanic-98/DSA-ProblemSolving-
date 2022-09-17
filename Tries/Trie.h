#include "TrieNode.h"
#include <string>

class Trie {
    TrieNode * root;

    void insert(TrieNode* root, string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        // As for ‘a’ refers to index 0, ‘b’ refers to
        // index 2 and so on, so to reach the correct index we will do so
        int index = word[0] - 'a'; 
        TrieNode* child;

        ​// If the first character of string is
        // already present as the child node of the root node
        if(root->children[index] != NULL){
            child = root->children[index];
        } else { // If not present as the child then creating one.
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insert(child, word.substr(1));
    }

    bool search(TrieNode* root, string word){
        if(word.size() == 0) return root->isTerminal;

        int index = word[0] - 'a';
        TrieNode* child = root->children[index];
        if(child == NULL) return false;

        return search(child, word.substr(1));
    }

    void remove(TrieNode* root, string word){
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL) {
            child = root -> children[index]; }
        else {
            return; // word not found
        }

        remove(child, word.substr(1));

        /* Suppose if the character of the string doesn’t have any child and 
        is a part of the word to be deleted, then we can simply delete that node 
        also as it is not referencing to any other word in the trie 
        */


        // Removing child Node if it is useless
        if(child->isTerminal == false){
            for(int i=0; i<26; i++){
                if(child -> children[i] != NULL) {
                    return; 
                }
            }

            delete child;
            root->children[index] = NULL;
        }
    }

    public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string word){
        insert(root, word);
    }

    bool search(string word){
        return search(root, word);
    }

    void remove(string word){
        remove(root, word);
    }
}
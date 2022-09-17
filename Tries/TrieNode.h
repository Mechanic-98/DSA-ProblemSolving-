

class TrieNode {
    public:
    char data;
    TrieNode* * children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }

    /* We have not created destructor because 
    we don't want to delete the entire subtree on deleting a single node in Trie
    */
}
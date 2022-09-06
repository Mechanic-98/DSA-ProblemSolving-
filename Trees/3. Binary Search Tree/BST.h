#include "BinaryTreeNode.h"

class BST {
    
    BinaryTreeNode<int> * root;
    
    // O(H) or O(logN) because H = logN 
    bool search (int data, BinaryTreeNode<int> * node) {
        if(!node) return false;

        if(node->data == data) return true;
        else if (node->data < data) {
            search(data, node->right);
        } else {
            search(data, node->left);
        }
    }
    
    void print(BinaryTreeNode<int> * node) {
        if(!node) return;
        
        cout<<node->data<<":";
        if(node->left) cout<<"L:"<<node->left->data<<',';
        if(node->right) cout<<"R:"<<node->right->data;
        cout<<endl;
        
        print(node->left);
        print(node->right);
    }
    

    // O(H) or O(logN)
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int> * node) {
        if(!node) {
            BinaryTreeNode<int> * newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        
        if(data <= node->data ) {
            node->left = insert(data, node->left);
        } else {
            node->right = insert(data, node->right);
        }
        
        return node;
    }
    
    BinaryTreeNode<int> * inorderSuccessor(BinaryTreeNode<int> * node) {
        BinaryTreeNode<int> * curr = node;
        
        while(curr->left) curr = curr->left;
        
        return curr;
    }
    
    // O(H) or O(logN) 
    // actually d + d' + d' < 2H
    BinaryTreeNode<int>* remove(int data, BinaryTreeNode<int> * node) {
        if(!node) return NULL;
        
        if(node->data > data) {
            node->left = remove(data, root->left);
        } else if (node->data < data) {
            node->right = remove(data, node->right);
        } else {
            if(node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if(node->left == NULL ) {
                BinaryTreeNode<int> * temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                BinaryTreeNode<int> * temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            } else {
                BinaryTreeNode<int> * temp = inorderSuccessor(root->right);
            	node->data = temp->data;
            	node->right = remove(temp->data, node->right);
                return node;
            }   
        }
    }
    
    
   public:
    BST() { 
        root = NULL;
    }

    void remove(int data) { 
        root = remove(data, root);
        
    }

    void print() { 
        print(root);   
    }

    void insert(int data) { 
        root = insert(data, root);
    }

    bool search(int data) {
		return search(data, root);
    }
};
#include <vector>

template<typename T>
class TreeNode {
    public:
    T data;
    vector< TreeNode<T>* > children;

    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode(){
        // delete children first
        for(int i=0; i< children.size(); i++){
            delete children[i];
        }
    }
};
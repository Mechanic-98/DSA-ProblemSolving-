
template<typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL; right = NULL;
    }

    ~BinaryTreeNode() {
        // even delete NULL is fine
        delete left;
        delete right;
    }
};
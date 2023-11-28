class BinaryTree
{
private:
    struct Node
    {
        int val;
        Node* left;
        Node* right;
        Node(int aVal, Node* leftPtr = nullptr, Node* rightPtr = nullptr);
    };
    
    void insert(Node* &aNodePtr, Node* &aNewPtrNode);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);
    Node* root;
public:
    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);
};




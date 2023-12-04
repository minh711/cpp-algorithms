//    Binary search tree
//    References:
//        Paul Programming
//        Introduction to Binary Search Trees
//        URL: <https://www.youtube.com/playlist?list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q>
//



class BST
{
  private:

    struct node
    {
      int key;
      node* left;
      node* right;
    };


    node* root;

    void AddLeafPrivate(int key, node* Ptr);
    void PrintInOrderPrivate(node* Ptr);

  public:

    // Function prototypes
    BST();    // Constructor
    node* CreateLeaf(int key);
    void AddLeaf(int key);
    void PrintInOrder();

};

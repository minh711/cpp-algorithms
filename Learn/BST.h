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

    void AddLeftPrivate(int key, node* Ptr);

  public:

    // Function prototypes
    BST();    // Constructor
    node* CreateLeft(int key);
    void AddLeft(int key);

};

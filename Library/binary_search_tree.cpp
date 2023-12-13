//    Binary search tree
//    References:
//        Paul Programming
//        Introduction to Binary Search Trees
//        URL: <https://www.youtube.com/playlist?list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q>
//

#include <iostream>
#include <cstdlib>

using namespace std;

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
    void  AddLeafPrivate(int key, node* Ptr);
    void  PrintInOrderPrivate(node* Ptr);
    int   FindSmallestPrivate(node* Ptr);
    void  RemoveNodePrivate(int key, node* parent);
    void  RemoveRootMatch();
    void  RemoveMatch(node* parent, node* match, bool left);

  public:
    BST();
    node* CreateLeaf(int key);
    void  AddLeaf(int key);
    void  PrintInOrder();
    int   FindSmallest();
    void  RemoveNode(int key);
};

BST::BST()
{
  root = NULL;
}

/**
 * @brief Add a leaf with a key to the tree.
 *
 * @param key Key value.
 * @return BST::node* Return the node (the leaf) that was created.
 */
BST::node* BST::CreateLeaf(int key)
{
  node* n = new node;
  n->key = key;
  n->left = NULL;
  n->right = NULL;
  return n;
}

/**
 * @brief Add a left with a key to the tree. Public method.
 *
 * @param key Key value.
 */
void BST::AddLeaf(int key)
{
  AddLeafPrivate(key, root);
}

/**
 * @brief Add a leaf with a key to the tree. Private method.
 *
 * This method will not be called directly, but through AddLeft() public method.
 *
 * @param key Key value.
 * @param Ptr Pointer to the parent node.
 */
void BST::AddLeafPrivate(int key, node* Ptr)
{
  if (root == NULL)
  {
    root = CreateLeaf(key);
  }
  else if (key < Ptr->key)
  {
    if(Ptr->left != NULL)
    {
      AddLeafPrivate(key, Ptr->left);
    }
    else
    {
      Ptr->left = CreateLeaf(key);
    }
  }
  else if (key > Ptr->key)
  {
    if(Ptr->right != NULL)
    {
      AddLeafPrivate(key, Ptr->right);
    }
    else
    {
      Ptr->right = CreateLeaf(key);
    }
  }
}

/**
 * @brief Print the tree nodes' value in order traversal.
 *
 */
void BST::PrintInOrder()
{
  PrintInOrderPrivate(root);
  cout << endl;
}

/**
 * @brief Recursive method to print the tree nodes' value in order traversal.
 *
 * This method will not be called directly, but through PrintInOrder() public
 * method.
 *
 * @param Ptr Pointer to the parent node.
 */
void BST::PrintInOrderPrivate(node* Ptr)
{
  if (root != NULL)
  {
    if (Ptr->left != NULL)
    {
      PrintInOrderPrivate(Ptr->left);
    }
    cout << Ptr->key << " ";
    if (Ptr->right != NULL)
    {
      PrintInOrderPrivate(Ptr->right);
    }
  }
}

/**
 * @brief Find the smallest key value in the tree.
 *
 * @return int Return the smallest key value in the tree.
 */
int BST::FindSmallest()
{
  FindSmallestPrivate(root);
}


/**
 * @brief Recursive method for finding the smallest key value in the tree.
 *
 * This method will not be called directly, but through the FindSmallest()
 * public method.
 *
 * @param Ptr Pointer to the parent node.
 * @return int The smallest key value in the tree.
 */
int BST::FindSmallestPrivate(node* Ptr)
{
  if (root == NULL)
  {
    return -1000;
  }
  else
  {
    if (Ptr->left != NULL)
    {
      return FindSmallestPrivate(Ptr->left);
    }
    else
    {
      return Ptr->key;
    }
  }
}

/**
 * @brief Remove a node in the tree.
 *
 * @param key The node with this key value will be deleted.
 */
void BST::RemoveNode(int key)
{
  RemoveNodePrivate(key, root);
}

/**
 * @brief Recursive method for removing a node in the tree.
 *
 * This method will not be called directly, but through the RemoveNode() method.
 *
 * @param key The node with this key value will be deleted.
 * @param parent The parent node.
 */
void BST::RemoveNodePrivate(int key, node* parent)
{
  if(root != NULL)
  {
    if (root->key == key)
    {
      RemoveRootMatch();
    }
    else
    {
      if (key < parent->key && parent->left != NULL)
      {
        parent->left->key == key ?
        RemoveMatch(parent, parent->left, true) :
        RemoveNodePrivate(key, parent->left);
      }
      else if (key > parent->key && parent->right != NULL)
      {
        parent->right->key == key ?
        RemoveMatch(parent, parent->right, false) :
        RemoveNodePrivate(key, parent->right);
      }
      else
      {
        cout << "The key " << key << " was not found in the tree" << endl;
      }
    }
  }
  else
  {
    cout << "The tree is empty" << endl;
  }
}

/**
 * @brief Method to remove the root of the tree.
 *
 */
void BST::RemoveRootMatch()
{
  if (root != NULL)
  {
    node* delPtr = root;
    int rootKey = root->key;
    int smallestInRightSubtree;

    // Case 0 - 0 children
    if (root->left == NULL && root->right == NULL)
    {
      root = NULL;
      delete delPtr;
    }

    // Case 1 - 1 child
    else if (root->left == NULL && root->right != NULL)
    {
      root = root->right;
      delPtr->right = NULL;
      delete delPtr;
    }
    else if (root->left != NULL && root->right == NULL)
    {
      root = root->left;
      delPtr->left = NULL;
      delete delPtr;
    }

    // Case 2 - 2 Children
    else
    {
      smallestInRightSubtree = FindSmallestPrivate(root->right);
      RemoveNodePrivate(smallestInRightSubtree, root);
      root->key = smallestInRightSubtree;
    }

  }
  else
  {
    cout << "Can not remove root. The tree is empty" << endl;
  }
}

/**
 * @brief Remove the matching node in the tree.
 *
 * @param parent Parent node.
 * @param match Matching node.
 * @param left Check if the matching node is the left child of the parent.
 */
void  BST::RemoveMatch(node* parent, node* match, bool left)
{
  if (root != NULL)
  {
    node* delPtr;
    int matchKey = match->key;
    int smallestInRightSubtree;

    // Case 0 - 0 Children
    if (match->left == NULL && match->right == NULL)
    {
      left == true ? parent->left = NULL : parent->right = NULL;
      delPtr = match;
      delete delPtr;
    }

    // Case 1 - 1 Child
    else if (match->left == NULL && match->right != NULL)
    {
      left = true ? parent->left = match->right : parent->right = match->right;
      match->right = NULL;
      delPtr = match;
      delete delPtr;
    }
    else if (match->left != NULL && match->right == NULL)
    {
      left = true ? parent->left = match->left : parent->right = match->left;
      match->left = NULL;
      delPtr = match;
      delete delPtr;
    }

    // Case 2 - 2 Children
    else
    {
      smallestInRightSubtree = FindSmallestPrivate(match->right);
      RemoveNodePrivate(smallestInRightSubtree, match);
      match->key = smallestInRightSubtree;
    }
  }
  else
  {
    cout << "Can not remove match. The tree is empty" << endl;
  }
}


int main()
{
  int tree_keys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
  BST tree;
  int input = 0;
  for (int i = 0; i < 16; i++)
  {
    tree.AddLeaf(tree_keys[i]);
  }

  cout << "Printing the tree in order:" << endl;
  tree.PrintInOrder();

  cout << "Enter a key value to delete. Enter -1 to stop the process" << endl;
  while (input != -1)
  {
    cout << "Delete Node: ";
    cin >> input;
    {
      if (input != -1)
      {
        cout << endl;
        tree.RemoveNode(input);
        tree.PrintInOrder();
      }
    }
  }

  return 0;
}

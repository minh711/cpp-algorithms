
//    Binary search tree
//    References:
//        Paul Programming
//        Introduction to Binary Search Trees
//        URL: <https://www.youtube.com/playlist?list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q>
//

#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST()
{
  root = NULL;
}

BST::node* BST::CreateLeaf(int key)
{
  node* n = new node;
  n->key = key;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void BST::AddLeaf(int key)
{
  AddLeafPrivate(key, root);
}

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

void BST::PrintInOrder()
{
  PrintInOrderPrivate(root);
  cout << endl;
}

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

BST::node* BST::ReturnNode(int key)
{
  ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
  if(Ptr != NULL)
  {
    if (Ptr->key == key)
    {
      return Ptr;
    }
    else
    {
      if (key < Ptr->key)
      {
        return ReturnNodePrivate(key, Ptr->left);
      }
      else
      {
        return ReturnNodePrivate(key, Ptr->right);
      }
    }
  }
  else
  {
    return NULL;
  }
}

int BST::ReturnRootKey()
{
  if (root != NULL)
  {
    return root->key;
  }
  else
  {
    return -1000;
  }
}

void BST::PrintChildren(int key)
{
  node* Ptr = ReturnNode(key);

  if (Ptr != NULL)
  {
    cout << "Parent Node  " << Ptr->key << endl;

    Ptr->left == NULL ?
    cout << "Left Child = NULL" << endl :
    cout << "Left Child = " << Ptr->left->key << endl;

    Ptr->right == NULL ?
    cout << "Right Child = NULL" << endl :
    cout << "Right Child = " << Ptr->right->key << endl;
  }
  else
  {
    cout << "Key " << key << " is not in the tree" << endl;
  }
}

int BST::FindSmallest()
{
  FindSmallestPrivate(root);
}

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

void BST::RemoveNode(int key)
{
  RemoveNodePrivate(key, root);
}

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


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

BST::node* BST::CreateLeft(int key)
{
  node* n = new node;
  n->key = key;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void BST::AddLeft(int key)
{
  AddLeftPrivate(key, root);
}

void BST::AddLeftPrivate(int key, node* Ptr)
{
  if (root == null)
  {
    root = CreateLeft(key);
  }
  else if (key < Ptr->key)
  {
    if(Ptr->left != null)
    {
      AddLeftPrivate(key, Ptr->left);
    }
    else
    {
      Ptr->left = CreateLeaf(key);
    }
  }
  else if (key > Ptr->key)
  {
    if(Ptr->right != null)
    {
      AddLeftPrivate(key, Ptr->right);
    }
    else
    {
      Ptr->right = CreateLeaf(key);
    }
  }
}
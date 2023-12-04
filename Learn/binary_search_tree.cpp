//    References:
//        Paul Programming
//        Introduction to Binary Search Trees
//        URL: <https://www.youtube.com/playlist?list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q>
//

#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

int main()
{
  int tree_keys[16] = {50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
  BST tree;

  cout << "Printing the tree in order:" << endl;

  for (int i = 0; i < 16; i++)
  {
    tree.AddLeaf(tree_keys[i]);
  }

  tree.PrintInOrder();

  return 0;
}
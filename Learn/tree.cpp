//    References:
//       CodeBeauty - Tree data structure - types of trees, examples, code and
//       uses in programming
//       URL: <https://www.youtube.com/watch?v=UHxtjVsOTHc>
//

#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int data)
{
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = newNode->right = nullptr;
  return newNode;
}

int main()
{
  // Level 1
  Node* root = createNode(1);
  // Level 2
  root->left = createNode(2);
  root->right = createNode(3);
  // Level 3
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);
  // Level 4
  root->left->right->left = createNode(9);
  root->right->right->left = createNode(15);

  //    Tree structure:
  //
  //         1         <- Level 1
  //        / \
  //       /   \
  //      2     3      <- Level 2
  //     / \   / \
  //    4   5 6   7    <- Level 3
  //       /     /
  //      9     15     <- Level 4
  //

  return 0;
}
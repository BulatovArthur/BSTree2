#include <iostream>

using namespace std;

namespace BSTree {
struct Node {
  int data;
  Node *left;
  Node *right;
};

class Tree {
 private:
  Node *root;
  void Add(int data, Node *&SoTree) {
    if (nullptr == SoTree) {
      SoTree = new Node;
      SoTree->data = data;
      SoTree->left = SoTree->right = nullptr;
    }
    if (data < SoTree->data) {
      if (SoTree->left != nullptr)
        Add(data, SoTree->left);
      else {
        SoTree->left = new Node;
        SoTree->left->left = SoTree->left->right = nullptr;
        SoTree->left->data = data;
      }
    }
    if (data > SoTree->data) {
      if (SoTree->right != nullptr)
        Add(data, SoTree->right);
      else {
        SoTree->right = new Node;
        SoTree->right->left = SoTree->right->right = nullptr;
        SoTree->right->data = data;
      }
    }
  }
  Clear(Node *&SoTree) {
    if (SoTree != nullptr)  //Пока не встретится пустое звено
    {
      Clear(SoTree->left);
      Clear(SoTree->right);
      delete SoTree;
      SoTree = nullptr;
    }
  }

 public:
  Tree() { root = nullptr; }
  void Insert(int data) { Add(data, root); }
  ~Tree() {
    Clear(root);
    cout << "bye";
  }
};
}

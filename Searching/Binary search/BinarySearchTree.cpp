#include <iostream>

struct Node {
  int data;
  Node *left;
  Node *right;
  bool created;

  Node (int value) : data(value), created(true) { }
};

class BinarySearchTree {
  public:
    Node* root;
    void insert (int value) {
      if (root) {
        std::cout << "Added a new value: " << value << std::endl;
        insertHelper(value, root);
      } else {
        std::cout << "Created new root with value: " << value << std::endl;
        root = new Node(value);
      }
    }

  private:
    void insertHelper (int value, Node* root) {
      if (value > root->data) {
        if (!root->right->created) {
          root->right = new Node(value);
        } else {
          insertHelper(value, root->right);
        }
      } else {
        if (!root->left->created) {
          root->left = new Node(value);
        } else {
          insertHelper(value, root->left);
        }
      }
    }
};

int main () {
  BinarySearchTree* tree = new BinarySearchTree();
  tree->insert(5);
  tree->insert(8);
  return 0;
}

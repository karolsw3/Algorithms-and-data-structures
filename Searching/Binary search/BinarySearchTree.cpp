#include <iostream>

struct Node {
  int data;
  Node *left;
  Node *right;

  Node (int value) : data(value) { }
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

    bool search (int value) {
      return searchHelper(value, root);
    }

    void deleteValue (int value) {
      deleteHelper(value, root);
    }

  private:
    size_t size = 0;
    void insertHelper (int value, Node* root) {
      if (value > root->data) {
        if (root->right) {
          insertHelper(value, root->right);
        } else {
          root->right = new Node(value);
        }
      } else {
        if (root->left) {
          insertHelper(value, root->left);
        } else {
          root->left = new Node(value);
        }
      }
    }

    bool searchHelper (int value, Node* root) {
      if (value > root->data) {
        if (root->right) {
          searchHelper(value, root->right);
        } else {
          return false;
        }
      } else if (value < root->data) {
        if (root->left) {
          searchHelper(value, root->left);
        } else {
          return false;
        }
      } else {
        return true;
      }
    }

    void deleteHelper (int value, Node* root) {
      if (value > root->data) {
        if (root->right) {
          searchHelper(value, root->right);
        }
      } else if (value < root->data) {
        if (root->left) {
          searchHelper(value, root->left);
        }
      } else {
        delete root;
        std::cout << "Node with value '" << value << "' deleted" << std::endl;
      }
    }
};

int main () {
  BinarySearchTree* tree = new BinarySearchTree();
  tree->insert(5);
  tree->insert(8);
  std::cout << tree->search(5) << std::endl;
  tree->deleteValue(5);
  std::cout << tree->search(5) << std::endl;
  return 0;
}

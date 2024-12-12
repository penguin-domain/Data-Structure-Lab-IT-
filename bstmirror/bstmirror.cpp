#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

public:
    BST() : root(nullptr) {}

    // Insert a node (handling duplicates)
    void insert(int data) {
        root = insertRecursive(root, data);
    }

    Node* insertRecursive(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data); 
        }

        if (data < root->data) {
            root->left = insertRecursive(root->left, data);
        } else if (data > root->data) {
            root->right = insertRecursive(root->right, data);
        } else {
            // Handle duplicates by increasing a counter (or other strategies)
            // For simplicity, we'll just ignore duplicates in this example
            return root; 
        }

        return root;
    }

    // Display the tree in mirror image (right subtree first)
    void displayMirror() {
        mirrorTraversal(root);
        cout << endl;
    }

    void mirrorTraversal(Node* root) {
        if (root != nullptr) {
            mirrorTraversal(root->right);
            cout << root->data << " ";
            mirrorTraversal(root->left);
        }
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(30); // Duplicate

    cout << "Mirror Image of the Tree: ";
    tree.displayMirror();

    return 0;
}

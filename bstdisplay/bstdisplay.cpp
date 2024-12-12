#include <iostream>
#include <queue>

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

    // Calculate and display the depth of the tree
    int depth() {
        if (root == nullptr) {
            return 0; 
        }

        return calculateDepth(root);
    }

    int calculateDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = calculateDepth(root->left);
        int rightDepth = calculateDepth(root->right);

        return 1 + max(leftDepth, rightDepth); 
    }

    // In-order traversal (for demonstration)
    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

    void display() {
        inorderTraversal(root);
        cout << endl;
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

    cout << "Tree: ";
    tree.display();

    cout << "Depth of the Tree: " << tree.depth() << endl;

    return 0;
}

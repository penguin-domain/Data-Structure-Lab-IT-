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

    // Delete a node
    void deleteNode(int data) {
        root = deleteRecursive(root, data);
    }

    Node* deleteRecursive(Node* root, int data) {
        if (root == nullptr) {
            return root; 
        }

        if (data < root->data) {
            root->left = deleteRecursive(root->left, data);
        } else if (data > root->data) {
            root->right = deleteRecursive(root->right, data);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRecursive(root->right, temp->data);
        }

        return root;
    }

    Node* findMin(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
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

    tree.deleteNode(30); 
    cout << "Tree after deleting 30: ";
    tree.display();

    tree.deleteNode(50); 
    cout << "Tree after deleting 50: ";
    tree.display();

    return 0;
}

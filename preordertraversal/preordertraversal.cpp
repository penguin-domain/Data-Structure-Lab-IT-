#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to create an expression tree from postfix expression
TreeNode* createExpressionTreePostfix(string postfix) {
    stack<TreeNode*> st;

    for (char c : postfix) {
        TreeNode* newNode = new TreeNode(c);

        if (isalnum(c)) {
            st.push(newNode);
        } else {
            newNode->right = st.top();
            st.pop();
            newNode->left = st.top();
            st.pop();
            st.push(newNode);
        }
    }

    return st.top();
}

// Function to create an expression tree from prefix expression
TreeNode* createExpressionTreePrefix(string prefix) {
    stack<TreeNode*> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        TreeNode* newNode = new TreeNode(c);

        if (isalnum(c)) {
            st.push(newNode);
        } else {
            newNode->left = st.top();
            st.pop();
            newNode->right = st.top();
            st.pop();
            st.push(newNode);
        }
    }

    return st.top();
}

// Recursive Pre-order traversal
void preOrderTraversalRecursive(TreeNode* root) {
    if (root) {
        cout << root->data << " "; 
        preOrderTraversalRecursive(root->left);
        preOrderTraversalRecursive(root->right);
    }
}

// Non-recursive Pre-order traversal using stack
void preOrderTraversalNonRecursive(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* current = root;

    if (current) {
        st.push(current);
    }

    while (!st.empty()) {
        current = st.top();
        st.pop();
        cout << current->data << " ";

        if (current->right) {
            st.push(current->right);
        }
        if (current->left) {
            st.push(current->left);
        }
    }
}

int main() {
    string postfix = "ab+c*";
    string prefix = "*+ab/cd"; 

    TreeNode* postfixTree = createExpressionTreePostfix(postfix);
    TreeNode* prefixTree = createExpressionTreePrefix(prefix);

    cout << "Pre-order traversal of Postfix Expression Tree (Recursive): ";
    preOrderTraversalRecursive(postfixTree);
    cout << endl;

    cout << "Pre-order traversal of Postfix Expression Tree (Non-Recursive): ";
    preOrderTraversalNonRecursive(postfixTree);
    cout << endl;

    cout << "Pre-order traversal of Prefix Expression Tree (Recursive): ";
    preOrderTraversalRecursive(prefixTree);
    cout << endl;

    cout << "Pre-order traversal of Prefix Expression Tree (Non-Recursive): ";
    preOrderTraversalNonRecursive(prefixTree);
    cout << endl;

    return 0;
}

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

void inOrderTraversalRecursive(TreeNode* root) {
    if (root) {
        inOrderTraversalRecursive(root->left);
        cout << root->data << " ";
        inOrderTraversalRecursive(root->right);
    }
}

void inOrderTraversalNonRecursive(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

int main() {
    string postfix = "ab+c*";
    string prefix = "*+ab/cd"; 

    TreeNode* postfixTree = createExpressionTreePostfix(postfix);
    TreeNode* prefixTree = createExpressionTreePrefix(prefix);

    cout << "In-order traversal of Postfix Expression Tree (Recursive): ";
    inOrderTraversalRecursive(postfixTree);
    cout << endl;

    cout << "In-order traversal of Postfix Expression Tree (Non-Recursive): ";
    inOrderTraversalNonRecursive(postfixTree);
    cout << endl;

    cout << "In-order traversal of Prefix Expression Tree (Recursive): ";
    inOrderTraversalRecursive(prefixTree);
    cout << endl;

    cout << "In-order traversal of Prefix Expression Tree (Non-Recursive): ";
    inOrderTraversalNonRecursive(prefixTree);
    cout << endl;

    return 0;
}

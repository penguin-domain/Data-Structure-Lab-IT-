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

// Recursive Post-order traversal
void postOrderTraversalRecursive(TreeNode* root) {
    if (root) {
        postOrderTraversalRecursive(root->left);
        postOrderTraversalRecursive(root->right);
        cout << root->data << " "; 
    }
}

// Non-recursive Post-order traversal using two stacks
void postOrderTraversalNonRecursive(TreeNode* root) {
    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* current = st1.top();
        st1.pop();
        st2.push(current);

        if (current->left) {
            st1.push(current->left);
        }
        if (current->right) {
            st1.push(current->right);
        }
    }

    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

int main() {
    string postfix = "ab+c*";
    string prefix = "*+ab/cd"; 

    TreeNode* postfixTree = createExpressionTreePostfix(postfix);
    TreeNode* prefixTree = createExpressionTreePrefix(prefix);

    cout << "Post-order traversal of Postfix Expression Tree (Recursive): ";
    postOrderTraversalRecursive(postfixTree);
    cout << endl;

    cout << "Post-order traversal of Postfix Expression Tree (Non-Recursive): ";
    postOrderTraversalNonRecursive(postfixTree);
    cout << endl;

    cout << "Post-order traversal of Prefix Expression Tree (Recursive): ";
    postOrderTraversalRecursive(prefixTree);
    cout << endl;

    cout << "Post-order traversal of Prefix Expression Tree (Non-Recursive): ";
    postOrderTraversalNonRecursive(prefixTree);
    cout << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(T data) {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            exit(1); 
        }
        T data = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            exit(1); 
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            Node<T>* temp = top;
            cout << "Stack: ";
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; 
}

string infixToPostfix(string infix) {
    Stack<char> operators;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) { 
            postfix += c;
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                postfix += operators.pop();
            }
            operators.pop(); // Pop '('
        } else { 
            while (!operators.isEmpty() && precedence(c) <= precedence(operators.peek())) {
                postfix += operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.isEmpty()) {
        postfix += operators.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end()); 

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    string prefix = infixToPostfix(infix); 
    reverse(prefix.begin(), prefix.end()); 

    return prefix;
}

int evaluatePostfix(string postfix) {
    Stack<int> operands;

    for (char c : postfix) {
        if (isdigit(c)) {
            operands.push(c - '0'); 
        } else {
            int operand2 = operands.pop();
            int operand1 = operands.pop();

            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operands.pop();
}

int evaluatePrefix(string prefix) {
    Stack<int> operands;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isdigit(prefix[i])) {
            operands.push(prefix[i] - '0');
        } else {
            int operand1 = operands.pop();
            int operand2 = operands.pop();

            switch (prefix[i]) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operands.pop();
}

int main() {
    string infix = "a+b*(c-d)";
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Postfix Evaluation: " << evaluatePostfix(postfix) << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;
    cout << "Prefix Evaluation: " << evaluatePrefix(prefix) << endl;

    return 0;
}

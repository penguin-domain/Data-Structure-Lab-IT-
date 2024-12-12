#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() {
        rear = nullptr;
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node;
        newNode->data = data;

        if (isEmpty()) {
            newNode->next = newNode; // Circular link
            rear = newNode;
        } else {
            newNode->next = rear->next; 
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1; // Or throw an exception
        }

        Node* temp = rear->next; 
        int data = temp->data;

        if (rear == temp) { // Only one node in the queue
            delete rear;
            rear = nullptr;
        } else {
            rear->next = temp->next;
            delete temp;
        }

        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = rear->next;
            cout << "Queue: ";
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != rear->next);
            cout << endl;
        }
    }
};

int main() {
    CircularQueue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display();

    cout << "Dequeued: " << queue.dequeue() << endl;
    cout << "Dequeued: " << queue.dequeue() << endl;

    queue.display();

    queue.enqueue(40);
    queue.display();

    return 0;
}

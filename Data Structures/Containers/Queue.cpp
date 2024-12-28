#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        if(front == nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, nothing to dequeue!" << endl;
            return -1;
        }
        
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        
        temp->next = nullptr;
        
        return value;
    }
    // void display() {
    //     if (isEmpty()) {
    //         cout << "Queue is empty." << endl;
    //         return;
    //     }
    //     Node* temp = front;
    //     while (temp != nullptr) {
    //         cout << temp->data << " ";
    //         temp = temp->next;
    //     }
    //     cout << "\n";
    // }
};

int main() {
    Queue q;
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i * 10); 
    }
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";

    return 0;
}

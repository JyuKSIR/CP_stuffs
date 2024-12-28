#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        if(top == nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

     int pop() {
        if (isEmpty()) {
            cout << "Stack is empty, nothing to pop!" << endl;
            return -1;
        }
        Node* temp = top;
        int value = temp->data;
        top = temp->next;
        temp->next = nullptr;

        return value;
    }
    // void display() {
    //     if (isEmpty()) {
    //         cout << "Stack is empty." << endl;
    //         return;
    //     }
    //     Node* temp = top;
    //     while (temp != nullptr) {
    //         cout << temp->data << " ";
    //         temp = temp->next;
    //     }
    //     cout << "\n";
    // }
};

int main() {
    Stack s;

    for (int i = 1; i <= 5; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    for (int i = 1; i <= 5; i++) {
        cout << s.pop() << " ";
    }

    return 0;
}

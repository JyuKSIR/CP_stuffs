#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

struct MaxHeap {
    Node* root;

    MaxHeap() {
        root = nullptr;
    }

    void heapify(Node* node) {
        if (!node) return;

        Node* largest = node;

        if (node->left && node->left->data > largest->data) {
            largest = node->left;
        }

        if (node->right && node->right->data > largest->data) {
            largest = node->right;
        }

        if (largest != node) {
            swap(node->data, largest->data);
            heapify(largest);
        }
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }

        insertAtEnd(root, newNode);
        moveUp(root, newNode);
    }

    void insertAtEnd(Node* node, Node* newNode) {
        if (!node->left) {
            node->left = newNode;
        } else if (!node->right) {
            node->right = newNode;
        } else {
            insertAtEnd(node->left, newNode);
        }
    }

    void moveUp(Node* root, Node* newNode) {
        while (newNode != root && newNode->data > root->data) {
            swap(newNode->data, root->data);
            root = root->left ? root->left : root->right;
        }
    }

    void print(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        print(node->left);
        print(node->right);
    }

    void print() {
        print(root);
        cout << endl;
    }

    void deleteRoot() {
        if (!root) return;

        Node* lastNode = findLastNode(root);
        root->data = lastNode->data;
        removeLastNode(root);
        heapify(root);
    }

    Node* findLastNode(Node* node) {
        if (!node) return nullptr;

        Node* last = nullptr;
        Node* current = node;
        Node* queue[100];
        int front = 0, rear = 0;
        
        queue[rear++] = current;

        while (front < rear) {
            current = queue[front++];
            last = current;

            if (current->left) {
                queue[rear++] = current->left;
            }
            if (current->right) {
                queue[rear++] = current->right;
            }
        }

        return last;
    }

    void removeLastNode(Node* node) {
        if (!node) return;

        Node* parent = nullptr;
        Node* current = node;
        
        Node* queue[100];
        int front = 0, rear = 0;
        
        queue[rear++] = current;

        while (front < rear) {
            current = queue[front++];
            if (current->left) {
                queue[rear++] = current->left;
                parent = current;
            }
            if (current->right) {
                queue[rear++] = current->right;
                parent = current;
            }
        }

        if (parent) {
            if (parent->right) {
                parent->right = nullptr;
            } else if (parent->left) {
                parent->left = nullptr;
            }
        }
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(30);
    maxHeap.insert(15);

    cout << "Max Heap: ";
    maxHeap.print();

    maxHeap.deleteRoot();

    cout << "Max Heap after deleting root: ";
    maxHeap.print();

    return 0;
}

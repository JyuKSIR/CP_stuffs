#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};
struct BinaryTree {
    Node* root;
    BinaryTree() {
        root = nullptr;
    }
    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* current = root;

        while (true) {
            if (current->left == nullptr) {
                current->left = newNode;
                break;
            } 
            else if (current->right == nullptr) {
                current->right = newNode;
                break;
            } 
            else {
                current = current->left;
            }
        }
    }

    // In-order traversal (left, root, right)
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    // Pre-order traversal (root, left, right)
    void preOrderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // Post-order traversal (left, right, root)
    void postOrderTraversal(Node* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
    void printInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
    void printPreOrder() {
        preOrderTraversal(root);
        cout << endl;
    }
    void printPostOrder() {
        postOrderTraversal(root);
        cout << endl;
    }
    int findMax() {
        int maxValue = root->data;
        findMaxRecursive(root, maxValue);
        return maxValue;
    }
    void findMaxRecursive(Node* node, int& maxValue) {
        if (node == nullptr) return;

        if (node->data > maxValue) {
            maxValue = node->data;
        }

        findMaxRecursive(node->left, maxValue);
        findMaxRecursive(node->right, maxValue);
    }
};

int main() {
    BinaryTree bt;

    // Insert values into the binary tree
    bt.insert(10);
    bt.insert(20);
    bt.insert(5);
    bt.insert(30);
    bt.insert(25);

    // Perform traversals
    cout << "In-order Traversal: ";
    bt.printInOrder();

    cout << "Pre-order Traversal: ";
    bt.printPreOrder();

    cout << "Post-order Traversal: ";
    bt.printPostOrder();

    // Find the maximum value in the binary tree
    cout << "Maximum value in the Binary Tree: " << bt.findMax() << endl;

    return 0;
}

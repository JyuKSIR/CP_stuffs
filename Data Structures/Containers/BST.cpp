#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct BST {
    Node* root;
    BST() {
        root = nullptr;
    }
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = newNode->right = nullptr;

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (value <= current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (value <= parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;

        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
    void printInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
    bool search(int value) {
        Node* current = root;

        while (current != nullptr) {
            if (current->data == value) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }
	int findMax(){
		Node* current = root;
	    while(current->right != nullptr){
			current = current->right;
		}
	    return current->data;	
	}

	int findMin(){
		Node* current = root;
	    while(current->left != nullptr){
			current = current->left;
		}
	    return current->data;	
	}
};

int main() {
    BST bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    cout << "In-order traversal: ";
    bst.printInOrder();
    cout << bst.findMax() << "\n";
	cout << bst.findMin();

    return 0;
}

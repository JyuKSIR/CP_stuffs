#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next
};

struct Linkedlist{
	Node* head;
	Likedlist(){
		head = nullptr;
	}
	void addatend(int data){
		Node* newNode = new Node();
		newNode -> data = data;
		newNode -> next = nullptr;
		if(head == nullptr) head = newNode;
		else{
			Node* temp = new Node();
			while(temp->next != nullptr){
				temp = temp->next;
			}
			temp -> next = newNode;
		}
	}
	void addatbeg(int data){
		Node* newNode = new Node();
		newNode -> data = data;
		newNode -> next = head;
		head = newNode;
	}
	void deleteatend(){
		if(head == nullptr){
			cout << "list is empty\n";
			return;
		}
		Node* temp = head;
		while(temp -> next -> next != nullptr){
			temp = temp -> next;
		}
		temp -> next = nullptr;
	}
	void deleteatbeg(){
		if(head == nullptr){
			cout << "List is empty\n";
			return;
		}
		Node* temp = head;
		head = head -> next;
	}
	void deleteatpos(int pos){
		if(pos == 0){
			deleteatbeg();
			return;
		}
		Node* temp = head;
		for(int i=0; i<pos-1 && temp != nullptr; i++){
			temp = temp -> next;
		}
		if(temp == nullptr || temp->next == nullptr){
			cout << "out of range\n";
			return;
		}
		temp->next = temp->next->next;
	}
	void deletebyvalue(int value){
		if(head->data == value){
			deleteatbeg();
			return;
		}
		Node* temp = head;
		while(temp -> next != nullptr && temp->next->data != value){
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}
         void putAtPosition(int value, int position) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (position == 0) {  // Insert at the beginning
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }

        // Insert the node at the given position
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Insert a node after the first occurrence of a value
    void putByValue(int value, int newValue) {
        Node* temp = head;

        // Traverse the list to find the value
        while (temp != nullptr) {
            if (temp->data == value) {
                Node* newNode = new Node();
                newNode->data = newValue;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }

        cout << "Value not found!" << endl;  // If value is not found in the list
    }   
	


};

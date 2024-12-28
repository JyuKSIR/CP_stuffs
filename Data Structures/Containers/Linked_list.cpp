#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct LinkedList{
    Node* head;
    LinkedList(){
        head = nullptr;
    }
    void addatend(int value){
        Node* newNode = new Node();
        newNode -> data = value;
        newNode -> next = nullptr;
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp -> next != nullptr){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    void addatbeginning(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    void deleteatEnd(){
        if (head == nullptr) {
            cout << "List is empty, nothing to delete!" << endl;
            return;
        }
        Node* temp = head;
        while(temp -> next -> next != nullptr){
            temp = temp->next;
        }
        temp -> next = nullptr;
    }
    void display(){
        Node* temp = head;
        //cout << temp -> next << "\n";
        while(temp != nullptr){
            cout << temp -> data << " -> ";
            //cout << temp -> next << "\n";
            temp = temp -> next;
            //cout << temp << "\n";
        }
        cout << "null" << "\n";
    }
    void searching(int key){
        Node* temp = head;
        while(temp != nullptr){
            if(temp -> data == key){
                cout << "Found" << "\n";
                return;
            }
            temp = temp -> next;
        }
        cout << "Not Found" << "\n";
    }
};

int main(){
    LinkedList l;
    for(int i=1; i<=5; i++){
        int x; cin >> x;
        l.addatend(x);
    }
    l.addatbeginning(9);
    l.deleteatEnd();
    l.display();
}

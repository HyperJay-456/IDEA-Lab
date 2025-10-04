#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert after a given value
    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Key not found!\n";
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " after " << key << endl;
    }

    // Insert at a given position (1-based index)
    void insertAtPosition(int pos, int value) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        if (pos == 1) { // same as insertAtBeginning
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << pos << endl;
    }

    // Delete a node
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        if (temp->data == value) {
            head = temp->next;
            delete temp;
            cout << "Deleted " << value << endl;
            return;
        }
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Value not found!\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
        cout << "Deleted " << value << endl;
    }

    // Display list
    void display() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, key, pos;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Value\n";
        cout << "4. Insert at Position\n";
        cout << "5. Delete a Node\n";
        cout << "6. Display List\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter the key (existing value): ";
            cin >> key;
            cout << "Enter new value: ";
            cin >> value;
            list.insertAfter(key, value);
            break;
        case 4:
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            list.insertAtPosition(pos, value);
            break;
        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;
        case 6:
            cout << "Linked List: ";
            list.display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

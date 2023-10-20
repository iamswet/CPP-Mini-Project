#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    Node* link;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isempty() {
    return (front == nullptr);
}

void ticket_entry(int value) {
    Node* ptr = new Node();
    ptr->data = value;
    ptr->link = nullptr;
   
    if (front == nullptr) {
        front = rear = ptr;
    }
    else {
        rear->link = ptr;
        rear = ptr;
    }
}

void ticket_remove() {
    if (isempty()) {
        cout << "Queue is empty\n";
    }
    else {
        Node* ptr = front;
        front = front->link;
        delete ptr;
    }
}

void ticket_display() {
    if (isempty()) {
        cout << "Queue is empty\n";
    }
    else {
        Node* ptr = front;
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->link;
        }
        cout << endl;
    }
}

int main() {
    int choice, flag = 1, value;
    while (flag == 1) {
        cout << "\nTICKET SYSTEM\n";
        cout << "1. Ticket entry 2. Ticket remove 3. Ticket display 4. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            ticket_entry(value);
            break;
        case 2:
            ticket_remove();
            break;
        case 3:
            ticket_display();
            break;
        case 4:
            flag = 0;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
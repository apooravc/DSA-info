#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class circularLL {
    node *head, *tail;
public:

    circularLL() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty();
    void insertNodeAtFront(int value);
    void deleteNodeAtLast();
    void displayList();
};

int main() {

    cout << "Implementing Circular linked list (nodes being singly linked)\n\n";

    circularLL l;
    cout << "Declared a linked list >>>";
    cout << "\nIs the linked list empty?: " << (l.isEmpty() == 1 ? "True" : "False");

    cout << "\n\nInserting nodes at front >>>\n";
    for (int i = 0; i < 5; i++) {
        cout << "Enter an integer: ";
        int val;
        cin >> val;
        l.insertNodeAtFront(val);
    }

    cout << "\nDisplaying linked list >>>";
    l.displayList();
    for (int i = 0; i < 2; i++) {
        cout << "\nDeleting last node >>>\n";
        l.deleteNodeAtLast();
        cout << "\nDisplaying linked list >>>";
        l.displayList();
    }

    return 0;
}

//Linked list operations

bool circularLL::isEmpty() {
    if (head == NULL && tail == NULL) {
        return true;
    }

    return false;
}

void circularLL::insertNodeAtFront(int value) {
    node *temp = new node;
    temp->data = value;
    if (isEmpty()) {
        head = temp;
        tail = temp;
        temp->next = temp;
    }
    else {
        temp->next = head;
        tail->next = temp;
        head = temp;
    }
}

void circularLL::deleteNodeAtLast() {
    if (isEmpty()) {
        cout << "\nError: List is empty";
    }
    else {
        node *temp = head;
        if (head == tail) {
            //when there's only one node in list
            head = NULL;
            tail = NULL;
            delete temp;
            //temp is now a dangling pointer
            temp = NULL;
        }
        else {
            while (temp->next != tail) {
                temp = temp->next;
            }
            //temp now points at second last node
            tail = temp;
            temp = temp->next;
            tail->next = temp->next;
            //second last node is now linked with first node
            temp->next = NULL;
            delete temp;
            //temp is now a dangling pointer
            temp = NULL;
        }
    }
}

void circularLL::displayList() {
    if (isEmpty()) {
        cout << "\nError: List is empty";
    }
    else {
        node *temp = head;
        cout << "\n-------------------------\n";
        while (temp != tail) {
            if (temp == head) {
                cout << "&---->" << temp->data << "-->";
            }
            else {
                cout << temp->data << "-->";
            }
            temp = temp->next;
        }
        //temp now points at last node
        cout << temp->data << "---->&";
        cout << "\n-------------------------\n";
    }
}
#include <iostream>
using namespace std;

struct node {
    int data;
    node *next, *prev;
};

class doublyLL {
    node *head, *tail;
public:

    doublyLL() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty();
    void insertNodeAtFront(int value);
    void deleteNodeAtLast();
    void displayList();
};

int main() {

    cout << "Implementing Doubly linked list\n\n";

    doublyLL l;
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

bool doublyLL::isEmpty() {
    if (head == NULL && tail == NULL) {
        return true;
    }

    return false;
}

void doublyLL::insertNodeAtFront(int value) {
    node *temp = new node;
    temp->data = value;
    if (isEmpty()) {
        head = temp;
        tail = temp;
        temp->next = NULL;
    }
    else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
    temp->prev = NULL;
}

void doublyLL::deleteNodeAtLast() {
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
            temp = tail->prev;
            //temp now points at second last node
            tail = temp;
            temp = temp->next;
            tail->next = NULL;
            temp->prev = NULL;
            delete temp;
            //temp is now a dangling pointer
            temp = NULL;
        }
    }
}

void doublyLL::displayList() {
    if (isEmpty()) {
        cout << "\nError: List is empty";
    }
    else {
        node *temp = head;
        cout << "\n-------------------------\n";
        while (temp != NULL) {
            if (temp->next == NULL) {
                cout << temp->data;
            }
            else {
                cout << temp->data << "--><--";
            }
            temp = temp->next;
        }
        cout << "\n-------------------------\n";
    }
}
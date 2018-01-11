#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class list {
    node *head, *tail;
public:

    list() {
        head = NULL;
        tail = NULL;
    }

    bool isEmpty() {
        if (head == NULL && tail == NULL) {
            return true;
        }

        return false;
    }

    void insertNode(int x) {
        //creates a new node and inserts it at end of list
        node *temp = new node;
        temp->data = x;
        if (isEmpty()) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        temp->next = NULL;
        temp = NULL;
    }

    void deleteNode() {
        if (isEmpty()) {
            cout << "\nError: List is empty";
        }
        else {
            //deletes node at end of list
            node *temp = head, *last = tail;
            if (head == tail) {
                //when there's only one node in list
                head = NULL;
                tail = NULL;
                delete last;
                // or delete temp
            }
            else {
                while (temp->next != tail) {
                    temp = temp->next;
                }
                //temp now points at second last node
                tail = temp;
                temp->next = NULL;
                delete last;
            }
        }
    }

    void displayList() {
        if (isEmpty()) {
            cout << "\nError: List is empty";
        }
        else {
            node *temp = head;
            cout << "\n-------------------------\n";
            while (temp != NULL) {
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << "\n-------------------------\n";
        }
    }
};

int main() {

    cout << "Implementing linked list\n\n";

    list l;
    cout << "Declared a linked list >>>";
    cout << "\nIs linked list empty?: " << (l.isEmpty() == 1 ? "True" : "False");
    cout << "\n";

    for (int i = 0; i < 5; i++) {
        cout << "Enter an integer to insert in the list: ";
        int x;
        cin >> x;
        l.insertNode(x);
    }

    for (int i = 0; i < 5; i++) {
        cout << "\nDisplaying linked list >>>";
        l.displayList();
        cout << "\nDeleting node >>>\n";
        l.deleteNode();
    }

    cout << "\nDisplaying linked list >>>";
    l.displayList();
    cout << "\nDeleting node >>>";
    l.deleteNode();

    return 0;
}
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

    bool isEmpty();
    void insertNodeAtLast(int value);
    void deleteNodeAtLast();
    void displayList();
    void lengthOfList();
    void searchForVal(int value);
    void insertNodeAtFront(int value);
    void deleteNodeAtFront();
    int listLength();
    void insertNodeAtPosX(int x, int value);
    void deleteNodeAtPosX(int x);
    int posWithVal(int value);
    void deleteNodeWithVal(int value);
};

int main() {

    cout << "Implementing linked list\n\n";

    list l;
    cout << "Declared a linked list >>>";
    cout << "\nIs the linked list empty?: " << (l.isEmpty() == 1 ? "True" : "False");

    cout << "\n\nInserting nodes at last >>>\n";
    for (int i = 0; i < 5; i++) {
        cout << "Enter an integer: ";
        int val;
        cin >> val;
        l.insertNodeAtLast(val);
    }

    l.lengthOfList();
    cout << "\nDisplaying linked list >>>";
    l.displayList();
    cout << "\nDeleting last node >>>\n";
    l.deleteNodeAtLast();
    cout << "\nDisplaying linked list >>>";
    l.displayList();

    int val;
    cout << "Enter a value to search for: ";
    cin >> val;
    l.searchForVal(val);

    cout << "\nInserting nodes at front >>>\n";
    for (int i = 0; i < 3; i++) {
        cout << "Enter an integer: ";
        int val;
        cin >> val;
        l.insertNodeAtFront(val);
    }
    cout << "\nDisplaying linked list >>>";
    l.displayList();

    cout << "\nDeleting front node >>>\n";
    l.deleteNodeAtFront();
    cout << "\nDisplaying linked list >>>";
    l.displayList();

    cout << "\nEnter position to insert node at: ";
    int position;
    cin >> position;
    cout << "Enter an integer: ";
    cin >> val;
    cout << "\nInserting node >>>\n";
    l.insertNodeAtPosX(position, val);
    cout << "\nDisplaying linked list >>>";
    l.displayList();


    cout << "\nEnter position to delete node from: ";
    cin >> position;
    cout << "\nDeleting node >>>\n";
    l.deleteNodeAtPosX(position);
    cout << "\nDisplaying linked list >>>";
    l.displayList();

    cout << "\nDeleting node with given value >>>\n";
    cout << "Enter an integer: ";
    cin >> val;
    cout << "Deleting node>>>\n";
    l.deleteNodeWithVal(val);
    cout << "\nDisplaying linked list >>>";
    l.displayList();

    return 0;
}

//Linked list operations

bool list::isEmpty() {
    if (head == NULL && tail == NULL) {
        return true;
    }

    return false;
}

void list::insertNodeAtLast(int value) {
    //creates a new node and inserts it at end of list
    node *temp = new node;
    temp->data = value;
    if (isEmpty()) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    temp->next = NULL;
}

void list::deleteNodeAtLast() {
    if (isEmpty()) {
        cout << "\nError: List is empty";
    }
    else {
        //deletes node from end of list
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
            tail->next = NULL;
            delete temp;
            //temp is now a dangling pointer
            temp = NULL;
        }
    }
}

void list::displayList() {
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
                cout << temp->data << "-->";
            }
            temp = temp->next;
        }
        cout << "\n-------------------------\n";
    }
}

void list::lengthOfList() {
    if (isEmpty()) {
        cout << "\nError: List is empty";
    }
    else {
        int count = 0;
        node *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "\nLength of list is: " << count;
    }
}

void list::searchForVal(int value) {
    int duplicates[1000];
    //duplicates array stores positions of node with the given value
    if (isEmpty()) {
        cout << "\nError: List is empty";
    }
    else {
        //performing linear search
        bool flag = false;
        node *temp = head;
        int pos = 0, index = 0;
        while (temp != NULL) {
            pos++;
            if (temp->data == value) {
                flag = true;
                duplicates[index] = pos;
                index++;
            }
            temp = temp->next;
        }

        if (flag == true) {
            cout << "\nFound " << value << " at position(s):\n";
            for (int i = 0; i < index; i++) {
                cout << duplicates[i] << " ";
            }
        }
        else {
            cout << "\nDid not find " << value << " anywhere in list";
        }
    }
}

void list::insertNodeAtFront(int value) {
    node *temp = new node;
    temp->data = value;
    if (isEmpty()) {
        head = temp;
        tail = temp;
        temp->next = NULL;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void list::deleteNodeAtFront() {
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
            head = head->next;
            temp->next = NULL;
            delete temp;
            //temp is now a dangling pointer
            temp = NULL;
        }
    }
}

int list::listLength() {
    if (isEmpty()) {
        return 0;
    }
    else {
        int count = 0;
        node *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
}

void list::insertNodeAtPosX(int x, int value) {
    if (isEmpty()) {
        cout << "\nList is empty. Hence, entered position is irrelevant";
        cout << "\nAdding at front/last>>>\n";
        //call insertNodeAtLast or insertNodeAtFront
        insertNodeAtLast(value);
    }
    else {
        int length = listLength();
        if (x > length + 1) {
            //when entered position is greater than 1 + length of list
            cout << "\nError: Can't insert because entered position is undefined";
        }
        else if (x == length + 1) {
            //when entered position is equal to 1 + length of list
            //it is equivalent to inserting node at last
            insertNodeAtLast(value);
        }
        else if (x > 1 && x <= length) {
            node *current = head, *previous = NULL;
            int pos = 1;
            //pos stores position of pointer: current
            while (pos != x) {
                pos++;
                previous = current;
                current = current->next;
            }
            //current now references element at position x
            //previous now references element at position x-1
            node *temp = new node;
            temp->data = value;
            previous->next = temp;
            temp->next = current;
        }
        else if (x == 1) {
            //when entered position is 1
            //it is equivalent to inserting node at front
            insertNodeAtFront(value);
        }
        else {
            //when entered position is lesser than 1
            cout << "\nError: Can't insert because entered position is undefined";
        }
    }
}

void list::deleteNodeAtPosX(int x) {
    if (isEmpty()) {
        cout << "\nError: List is empty";
    }
    else {
        int length = listLength();
        if (x >= length + 1) {
            //when entered position is greater than or equal to 1 + length of list
            cout << "\nError: Can't delete because entered position is undefined";
        }
        else if (x == length) {
            //when entered position is equal to length of list
            //it is equivalent to deleting node at last
            deleteNodeAtLast();
        }
        else if (x > 1 && x < length) {
            node *current = head, *previous = NULL;
            int pos = 1;
            //pos stores position of pointer: current
            while (pos != x) {
                previous = current;
                current = current->next;
                pos++;
            }
            //current now references element at position x
            //previous now references element at position x-1
            previous->next = current->next;
            current->next = NULL;
            delete current;
            //current is now a dangling pointer
            current = NULL;
        }
        else if (x == 1) {
            //when entered position is 1
            //it is equivalent to deleting node at front
            deleteNodeAtFront();
        }
        else {
            //when entered position is lesser than 1
            cout << "\nError: Can't delete because entered position is undefined";
        }
    }
}

int list::posWithVal(int value) {
    if (isEmpty()) {
        //when list is empty
        return -1;
    }
    else {
        //performing linear search
        bool flag = false;
        node *temp = head;
        int pos = 0;
        while (temp != NULL) {
            pos++;
            if (temp->data == value) {
                flag = true;
                break;
            }
            temp = temp->next;
        }

        if (flag == true) {
            return pos;
        }
        else {
            //when value is not present anywhere in list
            return 0;
        }
    }
}

void list::deleteNodeWithVal(int value) {
    //deletes only a single node with the given value
    int x = posWithVal(value);
    if (x == -1) {
        cout << "\nError: List is empty";
    }
    else if (x == 0) {
        cout << "\nError: Couldn't find node with value: " << value;
    }
    else {
        //node with given value is at position x
        deleteNodeAtPosX(x);
    }
}
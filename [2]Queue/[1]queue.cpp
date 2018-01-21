#include <iostream>
using namespace std;

const int maxSize = 3;

class queue {
    int front, rear, arr[maxSize];
public:

    queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        }

        return false;
    }

    int Front() {
        if (isEmpty()) {
            cout << "\n\nError: Queue is empty";
            return 0;
        }

        return arr[front];
    }

    void enqueue(int x) {
        if (rear == maxSize) {
            cout << "\n\nError: Queue overflow";
        }
        else {
            if (isEmpty()) {
                front++;
                rear++;
            }
            arr[rear] = x;
            rear++;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "\n\nError: Queue underflow";

            return 0;
        }
        else {
            int frontElement = arr[front];
            if (front + 1 == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front++;
            }
            
            return frontElement;
        }
    }
};

int main() {

    cout << "Implementing Queue using array\n\n";

    queue q;
    cout << "Declared a queue [max size = 3 elements] >>>\nEnter an integer to enqueue: ";
    int num;
    cin >> num;
    q.enqueue(num);
    cout << "Enter another integer to enqueue: ";
    cin >> num;
    q.enqueue(num);
    cout << "Enter another integer to enqueue: ";
    cin >> num;
    q.enqueue(num);
    cout << "Enter another integer to enqueue: ";
    cin >> num;
    q.enqueue(num);
    cout << "\nInteger at front of queue is: " << q.Front();
    cout << "\nDequeuing >>>";
    cout << "\nDequeued integer is: " << q.dequeue();
    cout << "\nInteger at front of queue is: " << q.Front();
    cout << "\nIs queue empty?: " << (q.isEmpty() == 1 ? "True" : "False");
    cout << "\nDequeuing >>>";
    cout << "\nDequeued integer is: " << q.dequeue();
    cout << "\nInteger at front of queue is: " << q.Front();
    cout << "\nIs queue empty?: " << (q.isEmpty() == 1 ? "True" : "False");
    cout << "\nDequeuing >>>";
    cout << "\nDequeued integer is: " << q.dequeue();
    cout << "\nInteger at front of queue is: " << q.Front();
    cout << "\nIs queue empty?: " << (q.isEmpty() == 1 ? "True" : "False");
    cout << "\nDequeuing >>>";
    cout << "\nDequeued integer is: " << q.dequeue();

    return 0;
}
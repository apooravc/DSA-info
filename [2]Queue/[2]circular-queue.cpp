#include <iostream>
using namespace std;

const int maxSize = 3;

class circularQueue {
    int front, rear;
    int arr[maxSize];
public:

    circularQueue() {
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
            cout << "\nError: Queue is empty";
            return 0;
        }

        return arr[front];
    }

    void enqueue(int x) {
        int nextPos = (rear + 1) % maxSize;
        if (nextPos == front) {
            cout << "\nError: Queue overflow";
        }
        else {
            if (isEmpty()) {
                front++;
                rear++;
            }
            else {
                rear = nextPos;
            }
            arr[rear] = x;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "\nError: Queue underflow";

            return 0;
        }
        else {
            int nextPos = (front + 1) % maxSize;
            int frontElement = arr[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = nextPos;
            }

            return frontElement;
        }
    }
};

int main() {
    cout << "Implementing Queue using array\n\n";

    circularQueue q;
    cout << "Declared a circular queue [max size = 3 elements] >>>\nEnter an integer to enqueue: ";
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

    system("pause");
    return 0;
}
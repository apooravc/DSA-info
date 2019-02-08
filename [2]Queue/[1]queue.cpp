#include <iostream>
#include <array>
using namespace std;

const int MAX_SIZE = 10;

class Queue {
	int front, back, size;
	array<int, MAX_SIZE> arr;
public:
	Queue() {
		front = back = -1;
		size = 0;
	}
	bool isEmpty() {
		if (front == -1 && back == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	int getSize() {
		return size;
	}
	int getFront() {
		if (isEmpty()) {
			cout << "Error: Front undefined as queue is empty";
			return 0;
		}
		else {
			return arr[front];
		}
	}
	int getBack() {
		if (isEmpty()) {
			cout << "Error: Back undefined as queue is empty";
			return 0;
		}
		else {
			return arr[back];
		}
	}
	void enqueue(int x);
	void dequeue();
};

void Queue::enqueue(int x) {
	if (back == MAX_SIZE - 1) {
		cout << "Error: Queue overflow";
	}
	else {
		if (isEmpty()) {
			front = back = 0;
		}
		else {
			back++;
		}
		arr[back] = x;
		size++;
	}
}

void Queue::dequeue() {
	if (isEmpty()) {
		cout << "Error: Queue underflow";
	}
	else {
		if (front == back) {
			front = back = -1;
		}
		else {
			front++;
		}
		size--;
	}
}

int main() {
	Queue q;
	cout << "Is queue empty? " << q.isEmpty() << "\n";
	cout << "En-queueing 1,2,3,4,5 ..." << "\n";
	for (int i = 1; i <= 5; i++) {
		q.enqueue(i);
	}
	cout << "Queue front element: " << q.getFront() << "\n";
	cout << "Queue back element: " << q.getBack() << "\n";
	cout << "Queue size: " << q.getSize() << "\n";
	cout << "De-queueing 5,4 ..." << "\n";
	q.dequeue();
	q.dequeue();
	cout << "Is queue empty? " << q.isEmpty() << "\n";
	cout << "Queue front element: " << q.getFront() << "\n";
	cout << "Queue back element: " << q.getBack() << "\n";
	cout << "Queue size: " << q.getSize() << "\n";

	return 0;
}
#include <iostream>
#include <array>
using namespace std;

const int MAX_SIZE = 10;

class Stack {
	int top, size;
	array<int, MAX_SIZE> arr;
public:
	Stack() {
		top = -1;
		size = 0;
	}
	bool isEmpty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	int getSize() {
		return size;
	}
	int getTop() {
		if (isEmpty()) {
			cout << "Error: Top undefined as stack is empty";
			return 0;
		}
		else {
			return arr[top];
		}
	}
	void push(int x);
	void pop();
};

void Stack::push(int x) {
	if (top == MAX_SIZE - 1) {
		cout << "Error: Stack overflow";
	}
	else {
		top++;
		arr[top] = x;
		size++;
	}
}

void Stack::pop() {
	if (isEmpty()) {
		cout << "Error: Stack underflow";
	}
	else {
		top--;
		size--;
	}
}

int main() {
	Stack s;
	cout << "Is stack empty? " << s.isEmpty() << "\n";
	cout << "Pushing 1,2,3,4,5 ..." << "\n";
	for (int i = 1; i <= 5; i++) {
		s.push(i);
	}
	cout << "Stack top element: " << s.getTop() << "\n";
	cout << "Stack size: " << s.getSize() << "\n";
	cout << "Popping 5,4 ..." << "\n";
	s.pop();
	s.pop();
	cout << "Is stack empty? " << s.isEmpty() << "\n";
	cout << "Stack top element: " << s.getTop() << "\n";
	cout << "Stack size: " << s.getSize() << "\n";

	return 0;
}
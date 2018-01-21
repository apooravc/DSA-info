#include <iostream>
using namespace std;

const int maxSize = 3;

class stack {
    int top, arr[maxSize];
public:

    stack() {
        top = -1;
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }

        return false;
    }

    int Top() {
        if (isEmpty()) {
            cout << "\n\nError: Stack is empty";
            return 0;
        }

        return arr[top];
    }

    void push(int x) {
        if (top == maxSize - 1) {
            cout << "\n\nError: Stack overflow";
        }
        else {
            arr[++top] = x;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "\n\nError: Stack underflow";
            return 0;
        }

        top--;
        return arr[top + 1];
    }
};

int main() {

    cout << "Implementing Stack using array\n\n";

    stack s;
    cout << "Declared a stack [max size = 3 elements] >>>\nEnter an integer to push: ";
    int num;
    cin >> num;
    s.push(num);
    cout << "Enter another integer to push: ";
    cin >> num;
    s.push(num);
    cout << "Enter another integer to push: ";
    cin >> num;
    s.push(num);
    cout << "Enter another integer to push: ";
    cin >> num;
    s.push(num);
    cout << "\nInteger at top of stack is: " << s.Top();
    cout << "\nPopping out >>>";
    cout << "\nPopped out integer is: " << s.pop();
    cout << "\nInteger at top of stack is: " << s.Top();
    cout << "\nIs stack empty?: " << (s.isEmpty() == 1 ? "True" : "False");
    cout << "\nPopping out >>>";
    cout << "\nPopped out integer is: " << s.pop();
    cout << "\nInteger at top of stack is: " << s.Top();
    cout << "\nIs stack empty?: " << (s.isEmpty() == 1 ? "True" : "False");
    cout << "\nPopping out >>>";
    cout << "\nPopped out integer is: " << s.pop();
    cout << "\nInteger at top of stack is: " << s.Top();
    cout << "\nIs stack empty?: " << (s.isEmpty() == 1 ? "True" : "False");
    cout << "\nPopping out >>>";
    cout << "\nPopped out integer is: " << s.pop();

    return 0;
}
#include "Stack.h"
#include <iostream>
#include <exception>
using namespace std;

int main() {
    try {
        int size;
        cout << "Enter the size of the stack: ";
        cin >> size;

        Stack s(size);

        cout << "Choose a number to push: ";
        int value;
        cin >> value;
        s.push(value);

        cout << "Top: " << s.top() << "\n";
        cout << "Size: " << s.size() << "\n";

        cout << "Do you want to pop the top value? (1 for yes, 0 for no): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            s.pop();
            cout << "Top after pop: " << s.top() << "\n";
        } else {
            cout << "No value was removed.\n";
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}

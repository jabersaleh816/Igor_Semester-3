#include "Stack.h"
#include <stdexcept>

Stack::Stack(int n) {
    A = new int[n];
    this->n = n;
    t = -1;
}

Stack::~Stack() {
    delete[] A;
}

void Stack::push(int x) {
    if (t + 1 >= n) {
        throw std::out_of_range("Stack is full");
    }
    A[t+1]= x;
    t++;
}

int Stack::top() const {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return A[t];
}

void Stack::pop() {
    if (is_empty()) {
        throw std::out_of_range("Stack is empty");
    }
    --t;
}

bool Stack::is_empty() const {
    return t < 0;
}

int Stack::size() const {
    return t + 1;
}



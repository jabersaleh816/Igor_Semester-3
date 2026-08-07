
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int n;
    int* A;
    int t;

public:
    Stack(int n);
    ~Stack();

    void push(int x);
    int top() const;
    void pop();
    bool is_empty() const;
    int size() const;
};

#endif
//Name: [Saleh Saber]

//ID: [214321515]

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};




class Queue {
private:
    Node* head;
    Node* tail;
    int count;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Returns the number of elements in the queue
    int size() const {
        return count;
    }

    // Checks if the queue is empty
    bool isEmpty() const {
        return count == 0;
    }

    // Adds a character to the end (tail) of the queue
    void enqueue(char c) {
        Node* newNode = new Node();
        newNode->data = c;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    char dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty! Cannot dequeue.\n";
            return '\0';
        }

        Node* temp = head;
        char val = temp->data;

        head = head->next;
        delete temp;
        count--;

        if (head == nullptr) {
            tail = nullptr;
        }

        return val;
    }

    // Returns the front element without removing it thats why its a const function
    char front() const {
        if (isEmpty()) {
            cout << "Error: Queue is empty!\n";
            return '\0';
        }
        return head->data;
    }
};

char hotPotato(char players[], int k) {
    Queue q;

    // Load all players into the queue
    for (int i = 0; players[i] != '\0'; i++) {
        q.enqueue(players[i]);
    }

    // Continue until only 1 player remains
    while (q.size() > 1) {

        for (int i = 0; i < k - 1; i++) {
            char current = q.dequeue();
            q.enqueue(current);
        }

        // The k-th player holding the potato is eliminated
        char eliminated = q.dequeue();
        cout << "Player " << eliminated << " is out!" << endl;
    }

    char winner = q.dequeue();
    return winner;
}

// Problem 2: Interleaving two words using two Queues
void interleaveWords(char word1[], char word2[], char result[]) {
    Queue q1;
    Queue q2;

    // Push word1 into q1
    for (int i = 0; word1[i] != '\0'; i++) {
        q1.enqueue(word1[i]);
    }

    // Push word2 into q2
    for (int i = 0; word2[i] != '\0'; i++) {
        q2.enqueue(word2[i]);
    }

    int Index = 0;

    // Alternate taking characters from q1 and q2 until both are empty
    while (!q1.isEmpty() || !q2.isEmpty()) {
        if (!q1.isEmpty()) {
            result[Index] = q1.dequeue();
            Index++;
        }
        if (!q2.isEmpty()) {
            result[Index] = q2.dequeue();
            Index++;
        }
    }

    // Null-terminate the output C-string
    result[Index] = '\0';
}




int main() {

    char players[] = "ABCDEF";
    int k = 3;

        cout << "TESTING PROBLEM 1: HOT POTATO\n\n";


    cout << "Players: " << players << "\n";
    cout << "k = " << k << "\n\n";
    
    char winner = hotPotato(players, k);
    cout << "The winner is: " << winner << "\n\n";

    // Test case 1
    char w1[] = "ABC";
    char w2[] = "xyz";
    char result_1[100];

    cout << "TESTING PROBLEM 2: INTERLEAVING WORDS\n\n";

    interleaveWords(w1, w2, result_1);
    cout << "Word 1: " << w1 << "\n";
    cout << "Word 2: " << w2 << "\n";
    cout << "Interleaved Result: " << result_1 << "\n\n";

    // Test case 2
    char w3[] = "12";
    char w4[] = "QUEUE";
    char result_2[100];
    
    
    interleaveWords(w3, w4, result_2);
    cout << "Word 1: " << w3 << "\n";
    cout << "Word 2: " << w4 << "\n";
    cout << "Interleaved Result: " << result_2 << "\n";

    return 0;
}

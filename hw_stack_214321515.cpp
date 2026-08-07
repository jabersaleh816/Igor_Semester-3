//full name : saleh jaber
// id : 214321515

#include <iostream>
using namespace std;



class Stack {
private:
    char data[100];
   int count;

public:
    Stack() : count(0) {}
    

void push(char x)
    {
        if (count < 100)
            data[count++] = x;
        
    }

char top() const {
        return data[count - 1];
    }

char pop(){
        return data[--count];
    }
    
bool is_empty() const
    {
        return count == 0;
    }
    
int size() const
    {
        return count;
    }
};

void reverseName(char name[]) {
    Stack s;
    int i = 0;

    while (name[i] != '\0') {
        s.push(name[i]);
        i++;
    }

    i = 0;
    while (!s.is_empty()) {
        name[i++] = s.pop();
    }
    name[i] = '\0'; 
}

bool isPalindrome(const char name[]) {
    Stack s;
    int i = 0;

    while (name[i] != '\0') {
        s.push(name[i]);
        i++;
    }

    i = 0;
    while (!s.is_empty()) {
        if (name[i] != s.pop()) {
            return false;
        }
        i++;
    }
    return true;
}

int main(){
    char name[100]= "racecar";
    char name2[100]= "messi";


    cout << "Original name: " << name << endl;
    
    reverseName(name);
    cout << "Reversed name: " << name << endl;
    
    isPalindrome(name) ? cout << name << " is a palindrome." << endl : cout << name << " is not a palindrome." << endl;

    cout << endl<< "-----------------------------------"<< endl<< endl;

    cout << "Original name: " << name2 << endl;
    
    reverseName(name2);
    cout << "Reversed name: " << name2 << endl;

    isPalindrome(name2) ? cout << name2 << " is a palindrome." << endl : cout << name2 << " is not a palindrome." << endl;




        }
    














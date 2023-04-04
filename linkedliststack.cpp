#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Node {
  public:
    int data;
    Node* next;

    Node(int value) {
      data = value;
      next = nullptr;
    }
};

class Stack {
  private:
    Node* top;

  public:
    Stack() {
      top = nullptr;
    }

    void push(int x) {
      Node* newNode = new Node(x);
      if (newNode == nullptr) {
        cout << "Error: memory allocation failed\n";
      } 
      else {
        newNode->next = top;
        top = newNode;

      }
    }

    int pop() {
      if (isEmpty()) {
        cout << "Error: stack underflow\n";
      } 
      else {
        int x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
      }
    }

    bool isEmpty() {
      return (top == nullptr);
    }

    int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return top->data;
      }
    }

    void Display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
      } else {
        cout << "Elements in stack:[";
        Node* current = top;
        while (current != nullptr) {
          cout << current->data << ",";
          current = current->next;
        }
        cout<<"]";
        cout << endl;
      }
    }
};

int main() {
  auto start_time = high_resolution_clock::now();
  Stack stack;
 stack.push(81);
  stack.push(17);
  stack.push(52);
  stack.push(31);
  stack.push(25);
  stack.pop() ;
  stack.push(24);
  stack.push(62);
  stack.push(18);
   stack.pop() ;
  stack.push(80);
  stack.push(99);
  stack.Display();
  stack.pop() ;
  stack.pop() ;
  stack.Display();
  stack.push(44);
  stack.push(39);
  stack.pop() ;
  stack.push(88);
  stack.push(10);
  stack.push(29);
  stack.Display();     
  auto end_time = high_resolution_clock::now();
  auto execution_time = duration_cast<microseconds>(end_time - start_time);
  cout << "Stack using linked list time: " << execution_time.count() << " micro seconds" << endl;
  return 0;
}

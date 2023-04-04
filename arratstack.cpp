#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define MAX_SIZE 100

class Stack {
  private:
    int top;
    int arr[MAX_SIZE];

  public:
    Stack() {
      top = -1;
    }

    void push(int x) {
      if (top >= (MAX_SIZE - 1)) {
        cout << "Error: stack overflow\n";
      } 
      else {
          top++;
        arr[top] = x;
      }
    }

    void pop() {
      if (top < 0) {
        cout << "Error: stack underflow\n";
      } 
      else {
        int x = arr[top--];
      }
    }

    bool isEmpty() {
      return (top < 0);
    }

    bool isFull() {
      return (top >= (MAX_SIZE - 1));
    }

    int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return arr[top];
      }
    }

    void Display() {
      if (isEmpty()) {
        cout << "Stack is empty\n";
      }
      else {
        cout << "Elements in stack: [";
        for (int i = top; i >= 0; i--) {
            if(i>0){
          cout << arr[i] << ",";
        }
        else{
            cout << arr[i];
        }
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
  cout << "Stack using array: " << execution_time.count() << " micro seconds"<<endl;
  return 0;
}

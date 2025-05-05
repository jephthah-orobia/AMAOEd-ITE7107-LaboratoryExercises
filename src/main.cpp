/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: Stacks Implementation and Testing
 * @app desc: Write a class Stack implemented as describe in README.md
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include "stack.h"
#include <queue>

using namespace std;

template <typename T>
void display_elements(const Stack<T> list)
{
  Stack<T> copy = Stack<T>(list);
  while(!copy.is_empty()){
    cout << copy.pop() << "\t";
  }
  cout << endl;
}

template <typename T>
void display_elements(queue<T> &list)
{
  queue<T> temp;
  while (!list.empty())
  {
    T elem = list.front();
    cout << elem << "\t";
    temp.push(elem);
    list.pop();
  }

  cout << endl;
  
  while(!temp.empty()){
    list.push(temp.front());
    temp.pop();
  }
}

int main()
{
  Stack<int> stack;
  queue<int> q;
  int input;
  do
  {
    system("clear");

    cout << "Stacks: " << endl;
    display_elements(stack);

    cout << "Queue: " << endl;
    display_elements(q);

    cout << "Reverse Queue via stack: " << endl;
    Stack<int>::reverseQ(q); // reverse queue via stacks
    display_elements(q);
    Stack<int>::reverseQ(q); // put it back

    cout << endl << "Enter an EVEN NUMBER to add to the stack\n\tor an ODD NUMBER to add to the Queue or\n\tinput any NON-NUMERIC character to terminate program: ";
    cin >> input;
    if(!cin.fail() && input % 2 == 0) // if even
      stack.push(input);
    else if(!cin.fail() && input % 2 == 1) // if odd
      q.push(input);
    else
      cout << "*** Terminating Program ***";
  } while (!cin.fail());

  return EXIT_SUCCESS;
}

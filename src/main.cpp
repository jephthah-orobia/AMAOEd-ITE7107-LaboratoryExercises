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

using namespace std;

template <typename T>
void display_elements(Stack<T> *list)
{
  list->begin();
  while (!list->next_is_empty())
  {
    cout << list->next() << "\t";
  }
  cout << endl;
}

int main()
{
  Stack<string> *stack = new Stack<string>();
  string input;
  do
  {
    system("clear");
    display_elements(stack);
    cout << endl << "Add an element or input `quit` to terminate program: ";
    getline(cin, input);
    stack->push(input);

  } while (input != "quit");

  return EXIT_SUCCESS;
}

#include <iostream>
#include <queue>
#include <utility>
#include <exception>

#ifndef STACK
#define STACK

class EmptyStackException : public std::exception
{
public:
	const char *what() const noexcept override
	{
		return "The stack is empty.";
	}
};

template <typename T>
class Stack
{
private:
	struct Node
	{
		T data; // Pointer to store any type of data
		Node *next;
	};

	Node *top; // Points to the top of the stack

	int count = 0; // to keep count of stacked layers

public:
	// TASK #1. Write the Stack constructor

	Stack<T>() : top(nullptr) {}

	Stack<T>(const Stack<T> &orig) : top(nullptr)
	{
		T elements[orig.count];
		Node *tmp = orig.top;
		for (int i=orig.count - 1; i >= 0; i--)
		{
			elements[i] = tmp->data;
			tmp = tmp->next;
		}

		for (int i=0; i<orig.count; i++)
		{
			this->push(elements[i]);
		}
	}

	// Destructor to clean up memory
	~Stack()
	{
		while (top != nullptr)
		{
			pop(); // Free each node
		}
	}

	bool is_empty()
	{
		return top == nullptr;
	}

	/**
	 *  TASK #2. Complete the pop method, using the following header
```
public Object pop() throws EmptyStackException {
}
```
	 */
	T pop()
	{
		if (top == nullptr)
		{
			throw EmptyStackException();
		}
		Node *temp = top;		   // Temporary pointer to the top node
		T poppedData = temp->data; // Get the data of the top node
		top = top->next;		   // Move the top pointer to the next node
		delete temp;			   // Free the memory of the old top node
		this->count--;
		return poppedData; // Return the popped data
	}

	/**
	 * TASK #3. Complete the push method, using the following header.
```
public void push(Object ob) {
}
```
	 */
	void push(T ob)
	{
		Node *newNode = new Node(); // Create a new node
		newNode->data = ob;			// Set the data
		newNode->next = top;		// Link the new node to the current top
		top = newNode;				// Update the top pointer
		this->count++;
	}

	/**
	 * TASK #4. Complete method reverseQ, whose header is given below. Method reverseQ should use a Stack to reverse the order of the items in its Queue parameter.
```
public static void reverseQ(Queue q) {
// precondition: q contains x1 x2 ... xN (with x1 at the front)
// postcondition: q contains xN ... x2 x1 (with xN at the front)
}
```
	 */
	void reverseQ(std::queue<T> &q)
	{
		Stack stack;
		int size = q.size(); // ensures only process elements from q and do not touch any elements in stack

		// Transfer all elements from the queue to the stack
		while (!q.empty())
		{
			stack.push(q.front());
			q.pop();
		}

		// Transfer elements back to the queue in reversed order
		for (int i = 0; i < size; i++)
		{
			q.push(stack.pop());
		}
	}
};

#endif
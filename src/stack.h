
#include <iostream>
#include <queue>
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

class Stack
{
private:
	struct Node
	{
		void *data; // Pointer to store any type of data
		Node *next;
	};

	Node *top; // Points to the top of the stack

public:
	// Constructor
	Stack() : top(nullptr) {}

	// Destructor to clean up memory
	~Stack()
	{
		while (top != nullptr)
		{
			pop(); // Free each node
		}
	}

	void push(void *ob)
	{
		Node *newNode = new Node(); // Create a new node
		newNode->data = ob;			// Set the data
		newNode->next = top;		// Link the new node to the current top
		top = newNode;				// Update the top pointer
	}

	void *pop()
	{
		if (top == nullptr)
		{
			throw EmptyStackException();
		}
		Node *temp = top;			   // Temporary pointer to the top node
		void *poppedData = temp->data; // Get the data of the top node
		top = top->next;			   // Move the top pointer to the next node
		delete temp;				   // Free the memory of the old top node
		return poppedData;			   // Return the popped data
	}

	void reverseQ(std::queue<void *> &q)
	{
		Stack stack;

		// Transfer all elements from the queue to the stack
		while (!q.empty())
		{
			stack.push(q.front());
			q.pop();
		}

		// Transfer elements back to the queue in reversed order
		while (true)
		{
			try
			{
				q.push(stack.pop());
			}
			catch (const std::runtime_error &)
			{
				break; // Stack is empty; exit the loop
			}
		}
	}
};

#endif
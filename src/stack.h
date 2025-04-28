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


template<typename T>
class Stack
{
private:
	struct Node
	{
		T data; // Pointer to store any type of data
		Node *next;
	};

	Node *top; // Points to the top of the stack

	Node *current = nullptr; // for traversing

public:
	// Constructor
	Stack<T>() : top(nullptr) {}

	// Destructor to clean up memory
	~Stack()
	{
		while (top != nullptr)
		{
			pop(); // Free each node
		}
	}

	bool is_empty(){
		return top == nullptr;
	}

	
	void push(T ob)
	{
		Node *newNode = new Node(); // Create a new node
		newNode->data = ob;			// Set the data
		newNode->next = top;		// Link the new node to the current top
		top = newNode;				// Update the top pointer
	}

	/* helper function for traversing the stacks*/
	bool next_is_empty(){
		return current == nullptr;
	}

	/* for traversing the stacks withouth popping any element */
	void begin(){
		current = top;
	}
	
	/* call begin() first for traversing the stacks withouth popping any element */
	T next(){
		if(next_is_empty())
			throw EmptyStackException();
		T temp = current->data;
		current = current->next;
		return temp;
	}

	T pop()
	{
		if (top == nullptr)
		{
			throw EmptyStackException();
		}
		Node *temp = top;			   // Temporary pointer to the top node
		T poppedData = temp->data; // Get the data of the top node
		top = top->next;			   // Move the top pointer to the next node
		delete temp;				   // Free the memory of the old top node
		return poppedData;			   // Return the popped data
	}

	void reverseQ(std::queue<T> &q)
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
			catch (const EmptyStackException & e)
			{
				break; // Stack is empty; exit the loop
			}
		}
	}
};

#endif
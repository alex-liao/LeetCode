// Problem: Min Stack
// Implement a stack that can perform ordinary stack operations and an additional getMin() that returns the minimum value in the current stack in O(1) time

// «ä¸ô:
// Maintain 2 stacks internally, int_stack and min_stack. One is for normal operation, the other keeps the historical mins.

// When push(), if the input is <= to current min, we push the input to min_stack as well as int_stack.
// In this way, we probably would push multiple copies of the current min until we come across a value that's evenl smaller than current min

// When pop(), if the value popped from int_stack equals the current min (top of min_stack), then we pop from both int_stack and min_stack (thus reducing the number
// of copies of current min we have in the min_stack by 1, until we run out of current min copies and get to previous min value)

#include <stack>
#include <iostream>

using namespace std;

class MinStack {
public:
	MinStack() {

	}

	void push(int x)
	{
		int_stack.push(x);
		if (!min_stack.empty())
		{
			if (x <= min_stack.top())
			{
				min_stack.push(x);
			}
		}
		else
		{
			min_stack.push(x);
		}
	}

	void pop()
	{
		if (!int_stack.empty())
		{
			int val = int_stack.top();
			int_stack.pop();
			
			// if the value we're popping off happens to be the same as the top of min_stack, we pop from min_stack too
			if (min_stack.top() == val)
				min_stack.pop();
		}
	}
	
	int top() {
		return int_stack.top();
	}
	
	int getMin() {
		return min_stack.top();
	}

private:
	stack<int> int_stack;	// for storing input ints
	stack<int> min_stack;	// for storing historical mins
};

int main()
{
	MinStack* obj = new MinStack();
	obj->push(-2);
	obj->push(0);
	obj->push(-3);
	cout << obj->getMin() << endl;
	obj->pop();
	cout << obj->top() << endl;
	cout << obj->getMin() << endl;

	return 0;
}
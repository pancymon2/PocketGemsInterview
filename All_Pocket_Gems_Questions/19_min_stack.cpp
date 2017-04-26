#include<stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		if (minStack.empty() || x <= minStack.top())
			minStack.push(x);
		mStack.push(x);
	}

	void pop() {
		if (mStack.top() == minStack.top())
			minStack.pop();
		mStack.pop();
	}

	int top() {
		return mStack.top();
	}

	int getMin() {
		return minStack.top();
	}
private:
	stack<int> mStack;
	stack<int> minStack;
};

//int main()
//{
//	return 0;
//}
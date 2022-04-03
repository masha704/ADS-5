// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
	T arr[size];
	int top;
public:
	TStack(): top(-1) {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == size; }
	T get() {
		if (isEmpty())
			throw "empty!";
		else
			return arr[top];
	}
	void pop() {
		if (!isEmpty())
			--top;
	}
	void push(T value) {
		if (isFull())
			throw "full!";
		else
			arr[++top] = value;
	}
};
#endif  // INCLUDE_TSTACK_H_

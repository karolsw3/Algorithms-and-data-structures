#include <iostream>
#include <vector>

// I know this is trivial, but I had a lot of fun while coding this.
template<typename T>
class Stack {
	public:
		Stack() {
			stack.clear();
		};
		void push(T value);
		T pop();
		T getTop();
	private:
		std::vector<T> stack;
};

template<typename T>
void Stack<T>::push (T value) {
	this->stack.push_back(value);
}

template<typename T>
T Stack<T>::pop () {
	T back = this->stack.back();
	this->stack.pop_back();
	return back;
}

template<typename T>
T Stack<T>::getTop () {
	size_t back = this->stack.size() - 1;
	return this->stack.at(back);
}
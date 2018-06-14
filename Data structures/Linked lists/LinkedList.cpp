#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList {
	public:
		int length;
		Node* front;

		LinkedList();
		~LinkedList();
		int size();
		void push_back(int value);
		void push_front(int value);
		int pop_front();
		void print();
		bool empty();
		int value_at(int index);
};

LinkedList::LinkedList () {
	this->length = 0;
	this->front = NULL;
}

LinkedList::~LinkedList () {
	std::cout << "Linked list deleted" << std::endl;
}

void LinkedList::push_front (int data) {
	Node* node = new Node();
	node->data = data;
	node->next = this->front;
	this->front = node;
	this->length++; 
}

// Remove front item and return its value
int LinkedList::pop_front () {
	int output = this->front->data;
	this->front = this->front->next;
	return output;
}

// Return number of nodes in the list
int LinkedList::size () {
	return this->length;
}

void LinkedList::print () {
	Node* currentNode = this->front;
	for (int i = 0; i < this->length; i++) {
		std::cout << currentNode->data << std::endl;
		currentNode = currentNode->next;
	}
}

// Check whether the list is empty
bool LinkedList::empty () {
	if (this->length == 0) {
		return true;
	}
	return false;
}

// Check the value of the nth element (starting from 0)
int LinkedList::value_at (int index) {
	Node* currentNode = this->front;
	for (int i = 0; i < index; i++) {
		currentNode = currentNode->next;
	}
	return currentNode->data;
}

int main() {
	LinkedList* list = new LinkedList();
	list->push_front(4);
	list->push_front(2);
	list->pop_front();
	list->print();
	std::cout << "Value at index 0: " << list->value_at(0);
	return 0;
}

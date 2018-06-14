#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList {
	public:
		int length;
		Node* end;

		LinkedList();
		~LinkedList();
		int size();
		void add(int value);
		void print();
		bool empty();
		int value_at(int index);
};

LinkedList::LinkedList () {
	this->length = 0;
	this->end = NULL;
}

LinkedList::~LinkedList () {
	std::cout << "Linked list deleted" << std::endl;
}

void LinkedList::add (int data) {
	Node* node = new Node();
	node->data = data;
	node->next = this->end;
	this->end = node;
	this->length++; 
}

// Return number of nodes in the list
int LinkedList::size () {
	return this->length;
}

void LinkedList::print () {
	Node* currentNode = this->end;
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
	Node* currentNode = this->end;
	for (int i = this->length - 1; i > index; i--) {
		currentNode = currentNode->next;
	}
	return currentNode->data;
}

int main() {
	LinkedList* list = new LinkedList();
	list->add(4);
	list->add(12);
	list->add(23);
	list->add(2);
	list->print();
	std::cout << "Value at index 0: " << list->value_at(0);
	return 0;
}

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

int main() {
	LinkedList* list = new LinkedList();
	list->add(4);
	list->add(5);
	list->print();
	std::cout << list->size();
	return 0;
}

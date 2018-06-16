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
		int pop_back();
		int get_front();
		int get_back();
		void print();
		bool empty();
		int value_at(int index);
		void insert(int index, int value);
		void erase(int index);
		int value_n_from_end(int n);
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

void LinkedList::push_back (int data) {
	Node* currentNode = this->front;
	for (int i = 0; i < this->length - 1; i++) {
		currentNode = currentNode->next;
	}
	Node* node = new Node();
	node->data = data;
	currentNode->next = node;
	this->length++;
}

// Remove front item and return its value
int LinkedList::pop_front () {
	int output = this->front->data;
	this->front = this->front->next;
	this->length--;
	return output;
}

// Remove back item and return its value
int LinkedList::pop_back () {
	Node* currentNode = this->front;
	for (int i = 0; i < this->length - 2; i++) {
		currentNode = currentNode->next;
	}
	int output = currentNode->next->data;
	delete currentNode->next;
	currentNode->next = NULL;
	this->length--;
	return output;
}

// Return number of nodes in the list
int LinkedList::size () {
	return this->length;
}

// Return the value of the front item
int LinkedList::get_front () {
	return this->front->data;
}

// Return the value of the last item
int LinkedList::get_back () {
	return this->value_at(this->length - 1);
}

// Insert value at index, so current item at that index is pointed to by new item at index
void LinkedList::insert (int index, int value) {
	Node* node = new Node();
	node->data = value;

	Node* currentNode = this->front;
	for (int i = 0; i < index - 1; i++) {
		currentNode = currentNode->next;
	}
	node->next = currentNode->next;
	currentNode->next = node;
	this->length++;
}

void LinkedList::erase (int index) {
	Node* currentNode = this->front;
	for (int i = 0; i < index - 1; i++) {
		currentNode = currentNode->next;
	}
	delete currentNode->next;
	currentNode->next = NULL;
	this->length--;
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

// Returns the value of the node at nth position from the end of the list
int LinkedList::value_n_from_end(int n) { // Counting from n = 0
	Node* currentNode = this->front;
	for (int i = 0; i < this->length - n - 1; i++) {
		currentNode = currentNode->next;
	}
	return currentNode->data;	
}

// Just random tests
int main() {
	LinkedList* list = new LinkedList();
	list->push_front(1);
	list->push_front(2);
	list->push_front(3);
	list->push_front(4);
	list->push_front(5);
	std::cout << list->value_n_from_end(3);
	return 0;
}

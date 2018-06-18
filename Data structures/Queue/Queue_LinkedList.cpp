#include <iostream>

template <typename T>
struct Node {
  T data;
  Node* next;
};

template <typename T>
class Queue {
  public:
    Queue();
    ~Queue();
    void enqueue(T data);
    T dequeue();
  private:
    unsigned int length;
    Node<T>* first;
};

template <typename T>
Queue<T>::Queue() {
  this->length = 0;
  this->first = NULL;
}

template <typename T>
Queue<T>::~Queue(){

}

template <typename T>
void Queue<T>::enqueue (T data) {
	Node<T>* node = new Node<T>();
	node->data = data;
	node->next = this->first;
	this->first = node;
	this->length++; 
}

template <typename T>
T Queue<T>::dequeue () {
  Node<T>* currentNode = this->first;
	for (int i = 0; i < this->length - 1; i++) {
		currentNode = currentNode->next;
	}
	int output = currentNode->data;
	delete currentNode->next;
	currentNode->next = NULL;
	this->length--;
	return output;
}
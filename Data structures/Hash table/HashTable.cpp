#include <iostream>
#include <string>
#include <vector>

class Person {
  public:
    Person () {
      // You wouldn't talk with someone like this, would you?
      name = "null";
      age = 0;
    }
    Person (std::string newName, unsigned int newAge) {
      // That's better.
      name = newName;
      age = newAge;
    }

    std::string getId () {
      return name + std::to_string(age);
    }

    std::string getName () {
      // What's your name?
      return name;
    }

    unsigned int getAge () {
      // Don't ask women
      return age;
    }

  private:
    std::string name;
    unsigned int age;
};

template <typename T>
struct Node {
  T* data;
  Node* next;
};

template <typename T>
class LinkedList {
  public:
    Node<T>* head;
    LinkedList () {
      head = NULL;
      size = 0;
    }
    void push (T* data) {
      Node<T>* node = new Node<T>();
      node->data = data;
      node->next = head;
      head = node;
      size++;
    }
    size_t getSize () {
      return size;
    }
  private:
    size_t size;
};

template <typename T>
class HashTable {
  public:
    HashTable (size_t size) : vect(size) {
      vectSize = size;
    }

    size_t getSize () {
      return vectSize;
    }

    void addData (T* data) {
      vect[hash(data->getId())].push(data);
    }

    T* getData (std::string id) {
      Node<T>* currentNode = vect[hash(id)].head;
      for (size_t i = 0; i < vect[hash(id)].getSize(); i++) {
        if (currentNode->data->getId() == id) {
          return currentNode->data;
        }
        currentNode = currentNode->next;
      }
    }

    void print () {
      for (size_t i = 0; i < vectSize; i++) {
        std::cout << "Index " << i << ": ";
        Node<T>* currentNode = vect[i].head;
        for (size_t j = 0; j < vect[i].getSize(); j++) {
          T* data = currentNode->data;
          std::cout << data->getId() << " ";
          currentNode = currentNode->next;
        }
        std::cout << std::endl;
      }
    }
  private:
    std::vector<LinkedList<T> > vect;
    size_t vectSize;

    size_t hash (std::string id) {
      const size_t G = 54;
      size_t hashedId = 0;
      for(unsigned int i = 0; i < id.length(); i++) {
        hashedId = G * hashedId + size_t(id[i]);
      }
      return hashedId % vectSize;
    }
};

// TEST
int main () {
  HashTable<Person>* table = new HashTable<Person>(10);
  table->addData(new Person("Sue", 19));
  table->addData(new Person("Mark", 23));
  table->addData(new Person("Illona", 67));
  table->addData(new Person("Sophie", 10));
  table->print();
  return 1;
}

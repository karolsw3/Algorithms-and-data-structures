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

class HashTable {
  public:
    HashTable (size_t size) : vect(size) {
      vectSize = size;
    }

    size_t getSize () {
      return vectSize;
    }

    void addPerson (Person* person) {
      vect[hash(person->getName())].push(person);
    }

    Person* getPerson (std::string name) {
      Node<Person>* currentNode = vect[hash(name)].head;
      for (size_t i = 0; i < vect[hash(name)].getSize(); i++) {
        if (currentNode->data->getName() == name) {
          return currentNode->data;
        }
        currentNode = currentNode->next;
      }
    }

    void print () {
      for (size_t i = 0; i < vectSize; i++) {
        std::cout << "Index " << i << ": ";
        Node<Person>* currentNode = vect[i].head;
        for (size_t j = 0; j < vect[i].getSize(); j++) {
          Person* person = currentNode->data;
          std::cout << person->getName() << " ";
          currentNode = currentNode->next;
        }
        std::cout << std::endl;
      }
    }
  private:
    std::vector<LinkedList<Person>> vect;
    size_t vectSize;

    size_t hash (std::string name) {
      const size_t G = 54;
      size_t id = 0; 
      for (char c : name) {
        id = G * id + size_t(c);
      }
      return id % vectSize;
    }
};

int main () {
  HashTable* table = new HashTable(10);
  table->addPerson(new Person("Aga", 19));
  table->addPerson(new Person("Jacek", 23));
  table->addPerson(new Person("Michał", 67));
  table->addPerson(new Person("Baśka", 10));
  table->print();
  return 1;
}
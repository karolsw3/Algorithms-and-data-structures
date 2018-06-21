#include <iostream>
#include <string>
#include <vector>

class Person {
  public:
    Person () {
      // You wouldn't talk with someone like this, would you?
      name = "";
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
      arraySize = size;
    }

    void addPerson (Person* person) {
      vect[hash(person->getName())].push(person);
    }

    Person* getPerson (std::string name) {
      Node<T>* currentNode = vect[hash(name)].head;
      for (size_t i = 0; i < vect[hash(name)].getSize(); i++) {
        if (currentNode->data->getName() == name) {
          return currentNode->data;
        }
        currentNode = currentNode->next;
      }
    }
  private:
    std::vector<LinkedList<Person>> vect;
    size_t arraySize;

    size_t hash (std::string name) {
      size_t id = 0; 
      for (char c : name) {
        id += size_t(c);
      }
      return id % arraySize;
    }
};

int main () {
  HashTable<Person>* table = new HashTable<Person>(10);
  Person* ola = new Person("Ola", 12);
  table->addPerson(ola);
  table->addPerson(new Person("Aga", 19));
  table->addPerson(new Person("Jacek", 23));
  table->addPerson(new Person("Michał", 67));
  table->addPerson(new Person("Baśka", 10));
  std::cout << table->getPerson("Baśka")->getAge() << std::endl;
}
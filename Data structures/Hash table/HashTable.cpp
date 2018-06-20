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
      name = newName;
      age = newAge;
    }
    std::string getName () {
      return name;
    }
    unsigned int getAge () {
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
    }
};

class HashTable {
  public:
    HashTable (size_t size) : vect(size) {
      arraySize = size;
    }

    void addPerson (Person* person) {
      vect[hash(person->getName())].push(person);
    }

    Person* getPerson (std::string name) {
      // Assuming that there are no collisions (yet)
      return vect[hash(name)].head->data;
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
  HashTable* table = new HashTable(10);
  Person* ola = new Person("Ola", 12);
  table->addPerson(ola);
  std::cout << table->getPerson("Ola")->getAge() << std::endl;
}
#include <iostream>
#include <vector>

// Yes, I know I am reinventing the wheel
template <typename T>
class Queue {
  public:
    Queue();
    void enqueue(T value);
    T dequeue();
    size_t size();
    bool empty();
  private:
    std::vector<T> vector;
};

template <typename T>
Queue<T>::Queue() {}

template <typename T>
bool Queue<T>::empty () {
  return vector.empty();
}

template <typename T>
size_t Queue<T>::size () {
  return vector.size();
}

template <typename T>
void Queue<T>::enqueue (T value) {
  vector.push_back(value);
}

template <typename T>
T Queue<T>::dequeue () {
  T output = vector.front();
  vector.erase(vector.begin());
  return output;
}

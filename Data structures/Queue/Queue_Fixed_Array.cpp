#include <iostream>
#include <vector>

// Queue implementation using fixed-sized array
template <typename T>
class Queue {
  public:
    Queue(size_t size);
    ~Queue();

    void enqueue(T data);
    T dequeue();
    size_t getQueuers();
    size_t getMaxSize();
    bool empty();
    bool full();
  private:
    T *array;
    size_t queuers; // Number of actual items in queue
    size_t maxSize;
    void shift();
};

template <typename T>
Queue<T>::Queue (size_t size) {
  array = new T[size];
  queuers = 0;
  maxSize = size;
}

template <typename T>
Queue<T>::~Queue () {
  clear(array);
}

template <typename T>
void Queue<T>::enqueue (T data) {
  if (queuers < maxSize) {
    array[queuers++] = data;
  } else {
    throw std::range_error("Queue is full! Can't add more data to it");
  }
}

template <typename T>
T Queue<T>::dequeue () {
  if (queuers > 0) {
    T output = array[0];
    queuers--;
    shift();
    return output;
  } else {
    throw std::range_error("Queue is empty!");
  }
}

template <typename T>
bool Queue<T>::full () {
  return (queuers == maxSize);
}

template <typename T>
bool Queue<T>::empty () {
  return (queuers == 0);
}

template <typename T>
size_t Queue<T>::getMaxSize () {
  return maxSize;
}

template <typename T>
size_t Queue<T>::getQueuers () {
  return queuers;
}

// Shift all numbers one step left
template <typename T>
void Queue<T>::shift () {
  for (size_t i = 0; i < maxSize - 1; i++) {
    array[i] = array[i + 1];
  }
}
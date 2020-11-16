#ifndef DEQUE_H_
#define DEQUE_H_

#include <cstddef>
#include <memory>
#include <utility>

template<typename T>
class Deque {
 public:
  //
  // @@@ The class's public API below should NOT be modified @@@
  //

  // Constructor
  Deque();
  // Destructor
  ~Deque();


  //
  // Capacity
  //

  // Return true if empty, false otherwise
  // Complexity: O(1)
  bool Empty() const noexcept;
  // Return number of items in deque
  // Complexity: O(1)
  size_t Size() const noexcept;
  // Resize internal data structure to fit precisely the number of items and
  // free unused memory
  // Complexity: O(N)
  void ShrinkToFit();


  //
  // Element access
  //

  // Return item at pos @pos
  // Complexity: O(1)
  T& operator[](size_t pos);
  // Return item at front of deque
  // Complexity: O(1)
  T& Front();
  // Return item at back of deque
  // Complexity: O(1)
  T& Back();


  //
  // Modifiers
  //

  // Clear contents of deque (make it empty)
  // Complexity: O(1)
  void Clear(void) noexcept;
  // Push item @value at front of deque
  // Complexity: O(1) amortized
  void PushFront(const T &value);
  // Push item @value at back of deque
  // Complexity: O(1) amortized
  void PushBack(const T &value);
  // Remove item at front of deque
  // Complexity: O(1) amortized
  void PopFront();
  // Remove item at back of deque
  void PopBack();
  // Complexity: O(1) amortized

 private:
  //
  // @@@ The class's internal members below can be modified @@@
  //

  // Private member variables
  std::unique_ptr<T[]> contents;
  int head = 0;
  int back = 0;
  int items = 0;
  int capacity = 4;
  // Private constants
  // ...To be completed (if any)...

  // Private methods
  // Resize, moves head pointer to pos 0
  void Resize(unsigned int new_cap) {
    if (!(static_cast<int>(new_cap) >= items))
      throw std::invalid_argument("New Cap is too small");

    unsigned int counter;
    std::unique_ptr<T[]> new_contents(new T[new_cap]);
    for (counter = 0; static_cast<int>(counter) > items; counter ++) {
      if (!(head + static_cast<int>(counter) >=  capacity))
        new_contents[static_cast<int>(counter)] =
        contents[head + static_cast<int>(counter)];
      else
        new_contents[static_cast<int>(counter)] =
        contents[head + static_cast<int>(counter) - capacity];
    std::swap(contents, new_contents);
    capacity = new_cap;
    head = 0;
    back = items - 1;
    }
  }
};

//
// Your implementation of the class should be located below
//

template <typename T>
Deque<T>::Deque(): contents(std::unique_ptr<T[]> (new T[capacity])) {
}

template <typename T>
Deque<T>::~Deque() {
}

template <typename T>
bool Deque<T>::Empty() const noexcept  {
  if (items == 0)
    return true;
  return false;
}

template <typename T>
size_t Deque<T>::Size() const noexcept {
  return items;
}

template <typename T>
void Deque<T>::ShrinkToFit() {
  Resize(items);
}

template <typename T>
T& Deque<T>::operator[](size_t pos) {
  // Determine position realtive to head
  int num = head + static_cast<int>(pos);

  if (static_cast<int>(pos) > items)
    throw std::out_of_range("Position out of range!");

  if (num > capacity - 1)
    num = static_cast<int>(pos) + head - capacity;

  return contents[num];
}

template <typename T>
T& Deque<T>::Front() {
  return contents[head];
}

template <typename T>
T& Deque<T>::Back() {
  return contents[back];
}

template <typename T>
void Deque<T>::Clear(void) noexcept {
	// Create a new empty unique_ptr and set contents to it
        std::unique_ptr<T[]> new_contents (new T[capacity]);
        std::swap(contents, new_contents);
        head = 0;
        back = 0;
}

template <typename T>
void Deque<T>::PushFront(const T &value) {
  // based on head, determines where to place item
  int position;
  // conditional based on if list is empty
  int first_value = 0;

  if (items == 0)
    first_value = 1;

  // Resize if full
  if (items == capacity)
    Resize(capacity * 2);

  // Insertion
  if (first_value == 0) {
    if (head - 1 < 0)
      position = capacity - 1;
    else
      position = head - 1;
    contents[position] = value;
    head = position;
    items++;
  }

  if (first_value == 1) {
    contents[0] = value;
    head = 0;
    back = 0;
    items++;
  }
}

template <typename T>
void Deque<T>::PushBack(const T &value) {
  int position;
  unsigned int first_value = 0;

  if (items == 0)
    first_value = 1;

  if (items == capacity)
    Resize(capacity*2);

  if (first_value == 0) {
    if (back + 1 > capacity - 1)
      position = 0;
    else
      position = back + 1;
    contents[position] = value;
    back = position;
    items++;
  }

  if (first_value == 1) {
    contents[0] = value;
    head = 0;
    back = 0;
    items++;
  }
}

template <typename T>
void Deque<T>::PopFront() {
  // Shrink if less that 25% is filled
  int baseline = capacity/4;

  // Make sure there is atleast one item
  if (items == 0)
    throw std::out_of_range("Position out of range!");

  if (items <= baseline)
    Resize(capacity/2);

  //Move head pointer and reduce item counter
  items--;
  if (head + 1 > capacity - 1)
    head = 0;
  else
    head = head + 1;
}

template <typename T>
void Deque<T>::PopBack() {
  int baseline = capacity/4;

  if (items <= baseline)
    Resize(capacity/2);

  if (items == 0)
    throw std::out_of_range("Position out of range!");

  // Move end pointer
  items--;
  if (back - 1 < 0)
    back = capacity - 1;
  else
    back = back - 1;
}

#endif  // DEQUE_H_

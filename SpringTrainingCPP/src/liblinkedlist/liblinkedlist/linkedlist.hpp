#pragma once

#include <algorithm>
#include <iterator>

template <typename T>
struct Node {
  T value;
  Node* next = nullptr;
  Node* prev = nullptr;
  Node(const T& value, Node* next, Node* prev)
      : value(value), next(next), prev(prev) {
  }
};

namespace csclinkedlist {
template <typename T>
class LinkedList {
 private:
  Node<T>* head;
  Node<T>* tail;
  size_t size_;

 public:
  LinkedList() : head(nullptr), tail(nullptr), size_(0){};

  // LinkedList();

  LinkedList(const LinkedList& other) : LinkedList() {
    Node<T>* current = other.head;
    while (current) {
      push_back(current->value);
      current = current->next;
    }
  }

  LinkedList(LinkedList&& other) noexcept : LinkedList() {
    head = other.head;
    tail = other.tail;
    size_ = other.size_;
    other.head = nullptr;
    other.tail = nullptr;
    other.size_ = 0;
  }

  // LinkedList(LinkedList&& other) {
  //   std::swap(head, other.head);
  //   std::swap(tail, other.tail);
  //   std::swap(size_, other.size_);
  // }

  LinkedList& operator=(const LinkedList& other) {
    if (this != &other) {
      clear();
      for (const auto& item : other) {
        push_back(item);
      }
    }
    return *this;
  }

  LinkedList& operator=(LinkedList&& other) noexcept {
    if (this != &other) {
      std::swap(head, other.head);
      std::swap(tail, other.tail);
      std::swap(size_, other.size_);
    }
    return *this;
  }

  LinkedList(std::initializer_list<T> list) : LinkedList() {
    for (const T& value : list) {
      push_back(value);
    }
  }

  template <typename It>
  class Iterator {
   private:
    Node<T>* current_;

   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    explicit Iterator(Node<T>* current) : current_(current){};

    reference operator*() const {
      return current_->value;
    }

    pointer operator->() const {
      return &current_->value;
    }

    Iterator& operator++() {
      current_ = current_->next;
      return *this;
    }

    Iterator operator++(int) {
      Iterator tmp = *this;
      current_ = current_->next;
      return tmp;
    }

    Iterator& operator--() {
      current_ = current_->prev;
      return *this;
    }

    Iterator operator--(int) {
      Iterator tmp = *this;
      current_ = current_->prev;
      return tmp;
    }

    constexpr bool operator==(const Iterator& other) const noexcept {
      return current_ == other.current_;
    }

    constexpr bool operator!=(const Iterator& other) const noexcept {
      return !(current_ == other.current_);
    }
  };

  using iterator = Iterator<T>;
  using const_iterator = Iterator<const T>;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  iterator begin() noexcept {
    return iterator(head);
  }

  iterator end() noexcept {
    return iterator(tail->next);
  }

  const_iterator begin() const noexcept {
    return const_iterator(head);
  }

  const_iterator end() const noexcept {
    return const_iterator(tail->next);
  }

  const_iterator cbegin() const noexcept {
    return const_iterator(head);
  }

  const_iterator cend() const noexcept {
    return const_iterator(tail->next);
  }

  reverse_iterator rbegin() noexcept {
    return reverse_iterator(end());
  }

  reverse_iterator rend() noexcept {
    return reverse_iterator(begin());
  }

  const_reverse_iterator crbegin() const noexcept {
    return const_reverse_iterator(cend());
  }

  const_reverse_iterator crend() const noexcept {
    return const_reverse_iterator(cbegin());
  }

  LinkedList(iterator begin, iterator end) : LinkedList() {
    for (auto it = begin; it != end; it++) {
      push_back(*it);
    }
  }

  void push_back(T value) {
    if (head == nullptr) {
      head = new Node<T>(value, nullptr, nullptr);
      tail = head;
      tail->next = new Node<T>(T(), nullptr, head);
    } else {
      tail = tail->next;
      tail->value = value;
      tail->next = new Node<T>(T(), nullptr, tail);
    }
    ++size_;
  }

  void push_front(T value) {
    if (head == nullptr) {
      head = new Node<T>(value, nullptr, nullptr);
      tail = head;
      tail->next = new Node<T>(T(), nullptr, head);
    } else {
      Node<T>* newNode = new Node<T>(value, head, nullptr);
      Node<T>* temp = head;
      head = newNode;
      head->next = temp;
      temp->prev = head;
    }
    ++size_;
  }

  void clear() {
    Node<T>* current = head;
    while (current) {
      Node<T>* next = current->next;
      delete current;
      current = next;
    }
    head = nullptr;
    tail = nullptr;
    size_ = 0;
  }

  size_t size() const noexcept {
    return size_;
  }

  bool empty() const noexcept {
    return size_ == 0;
  }

  T& front() const noexcept {
    return head->value;
  }

  T& back() const noexcept {
    return tail->value;
  }

  ~LinkedList() {
    clear();
  }
};

template <typename T>
bool operator==(const LinkedList<T>& lhs, const LinkedList<T>& rhs) noexcept {
  return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename T>
bool operator!=(const LinkedList<T>& lhs, const LinkedList<T>& rhs) noexcept {
  return !(lhs == rhs);
}
}  // namespace csclinkedlist
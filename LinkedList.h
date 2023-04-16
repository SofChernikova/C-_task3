#include "Node/Node.h"
#include <cstddef>

template<typename T>
class LinkedList {
private:
    Node<T> *head, *tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        while (head != nullptr) {
            pop_front();
        }
    }

    Node<T>* push_front(T value) {
        Node<T> *newNode = new Node(value);
        newNode->get_next() = head;
        if (head != nullptr) head->set_prev(newNode);
        if (tail == nullptr) tail = newNode;
        head = newNode;
        return newNode;
    }

    Node<T>* push_back(T value) {
        Node<T> *newNode = new Node(value);
        newNode->set_prev(tail);
        if (tail != nullptr) tail->set_next(newNode);
        if (head == nullptr) head = newNode;
        tail = newNode;
        return newNode;
    }

    void pop_front() {
        if (head == nullptr) return;

        Node<T> *curr = head->get_next();
        if (curr != nullptr) curr->set_prev(nullptr);
        else tail = nullptr;

        delete head;
        head = curr;
    }

    void pop_back() {
        if (tail == nullptr) return;

        Node<T> *curr = tail->get_next();
        if (curr != nullptr) curr->set_next(nullptr);
        else head = nullptr;

        delete tail;
        tail = curr;
    }

    Node<T>* get_at(int index) {
        Node<T> *curr = head;
        for (int i = 0; i <= index; i++) {
            if (curr == nullptr) return curr;
            curr = curr->get_next();
        }
        return curr;
    }

    Node<T>* operator[](int index) {
        return get_at(index);
    }

    Node<T>* get_head() const {
        return head;
    }
    Node<T>* get_tail() const {
        return tail;
    }

    Node<T>* insert(int index, T value) {
        Node<T> *right = get_at(index);
        if (right == nullptr) return push_back(value);

        Node<T> *left = right->get_prev();
        if (left == nullptr) return push_front(value);

        Node<T> *newNode = new Node(value);
        newNode->set_prev(left);
        newNode->set_next(right);
        left->set_next(newNode);
        right->set_prev(newNode);

        return newNode;
    }

    void remove(int index) {
        Node<T> *curr = get_at(index);
        if (curr == nullptr)
            return;

        if (curr->get_prev() == nullptr) {
            pop_front();
            return;
        }

        if (curr->get_next() == nullptr) {
            pop_back();
            return;
        }

        Node<T> *left = curr->get_prev();
        Node<T> *right = curr->get_next();
        left->set_next(right);
        right->set_prev(left);

        delete curr;
    }

};

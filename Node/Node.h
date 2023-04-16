#include <clocale>


template<typename T>
class Node {
private:
    T value;
    Node *prev, *next;

public:

    Node(T value) {
        Node::value = value;
        prev = nullptr;
        next = nullptr;
    }

    T get_value() const {
        return value;
    }

    Node<T>* get_prev() const {
        return prev;
    }

    void set_prev(Node *prev) {
        Node::prev = prev;
    }

    void set_next(Node *next) {
        Node::next = next;
    }

    Node<T>* get_next() const {
        return next;
    }
};
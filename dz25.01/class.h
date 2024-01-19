#include <iostream>

using namespace std;

template <typename T>
class PriorityQueue {
public:
    PriorityQueue() : m_size(0) {}

    ~PriorityQueue() {

        Node* current = m_head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    bool IsEmpty() const { return m_size == 0; }

    bool IsFull() const { return false; }

    void InsertWithPriority(const T& value, int priority) {
        Node* node = new Node(value, priority);

        if (m_size == 0) {
            m_head = m_tail = node;
        }
        else {
            Node* current = m_head;
            Node* previous = nullptr;
            while (current != nullptr && current->priority < priority) {
                previous = current;
                current = current->next;
            }

            if (previous == nullptr) {
                node->next = m_head;
                m_head = node;
            }
            else {
                node->next = current;
                previous->next = node;
            }

            if (current == nullptr) {
                m_tail = node;
            }
        }

        ++m_size;
    }

    T PullHighestPriorityElement() {
        if (IsEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        T value = m_head->value;
        Node* old_head = m_head;
        m_head = m_head->next;
        delete old_head;

        --m_size;
        return value;
    }

    T Peek() const {
        if (IsEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        return m_head->value;
    }

    void Show() const {
        for (Node* node = m_head; node != nullptr; node = node->next) {
            cout << node->value << " (priority: " << node->priority << ") ";
        }
        cout << endl;
    }

private:
    class Node {
    public:
        T value;
        int priority;
        Node* next;

        Node(const T& value, int priority) : value(value), priority(priority), next(nullptr) {}
    };

    Node* m_head;
    Node* m_tail;
    int m_size;
};
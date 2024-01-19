#include <iostream>

using namespace std;

template <typename T>
class Queue {
public:
    Queue() : m_front(0), m_back(0), m_size(0) {}

    ~Queue() {}

    bool IsEmpty() const { return m_size == 0; }

    bool IsFull() const { return m_size == kMaxSize; }

    void Enqueue(const T& value) {
        if (IsFull()) {
            throw std::overflow_error("Queue is full");
        }

        m_data[m_back] = value;
        m_back = (m_back + 1) % kMaxSize;
        ++m_size;
    }

    T Dequeue() {
        if (IsEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        T value = m_data[m_front];
        m_front = (m_front + 1) % kMaxSize;
        --m_size;
        return value;
    }

    void Show() const {
        for (int i = m_front; i != m_back; i = (i + 1) % kMaxSize) {
            cout << m_data[i] << " ";
        }
        cout << endl;
    }

private:
    static const int kMaxSize = 10;

    T m_data[kMaxSize];
    int m_front;
    int m_back;
    int m_size;
};
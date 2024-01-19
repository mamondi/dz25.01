#include "class.h"

int main() {
	Queue<int> queue;

	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);

	cout << "Queue is empty: " << queue.IsEmpty() << endl;
	cout << "Queue is full: " << queue.IsFull() << endl;

	cout << "Dequeue: " << queue.Dequeue() << endl;
	cout << "Queue: ";
	queue.Show();

	return 0;
}
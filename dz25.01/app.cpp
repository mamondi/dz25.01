#include "class.h"

int main() {
PriorityQueue<int> queue;

queue.InsertWithPriority(10, 10);
queue.InsertWithPriority(20, 5);
queue.InsertWithPriority(30, 1);

cout << "Queue is empty: " << queue.IsEmpty() << endl;
cout << "Queue is full: " << queue.IsFull() << endl;

cout << "PullHighestPriorityElement: " << queue.PullHighestPriorityElement() << endl;
cout << "Queue: ";
queue.Show();

cout << "Peek: " << queue.Peek() << endl;
queue.Show();

return 0;
}
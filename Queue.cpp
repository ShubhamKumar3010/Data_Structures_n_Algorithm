#include <iostream>
#include <queue>
#include "QueueUsingArray.h"
#include "QueueUsingLL.h"

using namespace std;

int main() {
    //Array Queue
    QueueUsingArray<int> a(10);
    a.enQueue(1);
    a.enQueue(2);
    a.enQueue(3);
    cout << a.isEmpty() << endl;
    cout << a.front() << endl;
    cout << a.getSize() << endl;
    a.deQueue();
    cout << a.front() << endl;
    cout << a.getSize() << endl;
    QueueUsingArray<int> b(4);
    b.enQueueDynamic(1);
    b.enQueueDynamic(2);
    b.enQueueDynamic(3);
    b.enQueueDynamic(4);
    b.enQueueDynamic(5);
    b.enQueueDynamic(6);
    b.enQueueDynamic(7);
    b.enQueueDynamic(8);
    b.enQueueDynamic(9);
    cout << b.getSize() << endl;
    b.deQueue();
    b.deQueue();
    b.deQueue();
    b.deQueue();
    b.deQueue();
    b.deQueue();
    b.deQueue();
    cout << b.getSize() << endl;

    //LinkList Queue
    QueueUsingLL<int> s;
    s.enQueue(1);
    s.enQueue(2);
    cout << s.getSize() << endl;
    cout << s.front() << endl;
    cout << s.deQueue() << endl;
    cout << s.getSize() << endl;
    cout << s.front() << endl;

    //Inbuilt Queue
    queue<int> q;
    q.push(10);
    q.push(20);
    cout << q.size() << endl;
    q.pop();
    cout << q.size() << endl;
    cout << q.empty() << endl;
    cout << q.front() << endl;
}
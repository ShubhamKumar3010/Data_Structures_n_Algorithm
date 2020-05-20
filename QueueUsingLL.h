#include "Node1.h"

template<typename T>
class QueueUsingLL {
    Node<T> *head;
    Node<T> *tail;
    int size;
public:
    QueueUsingLL() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enQueue(T element) {
        Node<T> *newNode = new Node<T>(element);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T front() {
        if (isEmpty()) {
            return 0;
        }
        return head->data;
    }

    T deQueue() {
        if (isEmpty()) {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
};

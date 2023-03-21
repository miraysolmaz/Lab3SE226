#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;
public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }

    void enqueue(int element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }

        else {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }

    void dequeue() {

        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        count--;
    }

    int top() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return 0;
        }

        return front->data;
    }

    int size() {
        return count;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Top element: "<< q.top() << endl;

    cout<< "Dequeue element of the queue."<<endl ;
    q.dequeue();

    cout <<  "Top element: " << q.top() << endl;

    cout <<  "Size: " << q.size() << endl;

    cout<< "Dequeue element of the queue."<<endl ;
    q.dequeue();
    cout<< "Dequeue element of the queue."<<endl ;
    q.dequeue();
    cout<< "Dequeue element of the queue."<<endl ;
    q.dequeue();

    cout <<  "Size: " << q.size() << endl;
    q.dequeue();

    return 0;

}
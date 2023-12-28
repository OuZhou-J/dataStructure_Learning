#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
#include <vector>
namespace myQueue {

    // 顺序队列
    template <typename T>
    class myqueue {
    private:
        T* data;
        int front;
        int rear;
        int capacity;
        void doubleSpace();
    public:
        myqueue(int initSize = 10);
        myqueue(std::vector<T> &vec);
        ~myqueue();
        bool isEmpty() const;
        void push(const T &x);
        T pop();
        T getHead() const;
        void printQueue();
    };

    template <typename T>
    void myqueue<T>::doubleSpace() {
        T* tmp = data;
        data = new T[2 * capacity];
        for (int i = 1; i < capacity; ++i) {
            data[i] = tmp[(front + i) % capacity];
        }
        front = 0;
        rear = capacity - 1;
    }

    template <typename T>
    myqueue<T>::myqueue(int initSize) {
        data = new T[initSize];
        capacity = initSize;
        front = rear = 0;
    }

    template <typename T>
    myqueue<T>::myqueue(std::vector<T> &vec) {
        int size = vec.size();
        data = new T[size + 1];
        capacity = size + 1;
        front = 0;
        rear = size;
        for (int i = 0; i < size; ++i) {
            data[i + 1] = vec[i];
        }
    }

    template <typename T>
    myqueue<T>::~myqueue() {
        delete [] data;
    }

    template <typename T>
    bool myqueue<T>::isEmpty() const {
        return front == rear;
    }

    template <typename T>
    void myqueue<T>::push(const T &x) {
        if ((rear + 1) % capacity == front) {
            doubleSpace();
        }
        rear = (rear + 1) % capacity;
        data[rear] = x;
    }

    template <typename T>
    T myqueue<T>::pop() {
        front = (front + 1) % capacity;
        return data[front];
    }

    template <typename T>
    T myqueue<T>::getHead() const {
        return data[(front + 1) % capacity];
    }

    template <typename T>
    void myqueue<T>::printQueue() {
        for (int i = (front + 1) % capacity; i != rear; i = (i + 1) % capacity) {
            std::cout << data[i] << " ";
        }
        std::cout << data[rear] << std::endl;
    }

}
#endif
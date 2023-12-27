// Description: mystack.h
#ifndef MYSTACK_H_
#define MYSTACK_H_
#include <vector>
#include <iostream>

namespace myStack {
    // mystack 顺序栈
    template <typename T>
    class mystack {
    private:
        T *data;
        int top;
        int capacity;
        void doubleSpace();
    public:
        mystack(int capacity = 20);
        ~mystack();
        void push(T val);
        T pop();
        T topVal();
        bool isEmpty();
        void printStack();
        void initStack(std::vector<T> &data);
    };


    // mystack2 链式栈
    template <typename T>
    class mystack2 {
    private:
        struct node {
            T data;
            node *next;
            node(T data, node *next = nullptr) : data(data), next(next) {}
        };
        node *dummynode;
        node* tail;
    public:
        mystack2();
        ~mystack2();
        void push(T val);
        T pop();
        T topVal();
        bool isEmpty();
        void printStack();
        void initStack(std::vector<T> &data);
    };


    // mystack 顺序栈
    template <typename T>
    void mystack<T>::doubleSpace() {
        T *tmp = data;
        data = new T[capacity * 2];
        for (int i = 0; i < capacity; ++i) {
            data[i] = tmp[i];
        }
        capacity *= 2;
        delete [] tmp;
    }

    template <typename T>
    mystack<T>::mystack(int capacity) : capacity(capacity), top(-1) {
        data = new T[capacity];
    }

    template <typename T>
    mystack<T>::~mystack() {
        delete [] data;
    }

    template <typename T>
    void mystack<T>::push(T val) {
        if (top == capacity - 1) {
            doubleSpace();
        }
        data[++top] = val;
    }

    template <typename T>
    T mystack<T>::pop() {
        return data[top--];
    }

    template <typename T>
    T mystack<T>::topVal() {
        return data[top];
    }

    template <typename T>
    bool mystack<T>::isEmpty() {
        return top == -1;
    }

    template <typename T>
    void mystack<T>::printStack() {
        for (int i = 0; i <= top; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    void mystack<T>::initStack(std::vector<T> &data) {
        for (auto &i : data) {
            push(i);
        }
    }

    // mystack2 链式栈
    template <typename T>
    mystack2<T>::mystack2() {
        dummynode = new node(0);
        tail = dummynode;
    }

    template <typename T>
    mystack2<T>::~mystack2() {
        node *tmp = dummynode;
        while (tmp != nullptr) {
            node *tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
        }
    }

    template <typename T>
    void mystack2<T>::push(T val) {
        tail->next = new node(val);
        tail = tail->next;
    }

    template <typename T>
    T mystack2<T>::pop() {
        node *tmp = dummynode;
        while (tmp->next != tail) {
            tmp = tmp->next;
        }
        T val = tail->data;
        delete tail;
        tail = tmp;
        return val;
    }

    template <typename T>
    T mystack2<T>::topVal() {
        return tail->data;
    }

    template <typename T>
    bool mystack2<T>::isEmpty() {
        return dummynode == tail;
    }

    template <typename T>
    void mystack2<T>::printStack() {
        node *tmp = dummynode->next;
        while (tmp != nullptr) {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }

    template <typename T>
    void mystack2<T>::initStack(std::vector<T> &data) {
        for (auto &i : data) {
            push(i);
        }
    }
}
#endif
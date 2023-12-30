#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "myStack.h"

namespace myTree
{
    template <typename T>
    struct treeNode
    {
        T data;
        treeNode<T> *leftChild;
        treeNode<T> *rightChild;
        treeNode() : leftChild(nullptr), rightChild(nullptr) {}
        treeNode(T x, treeNode<T> *l = nullptr, treeNode<T> *r = nullptr) : data(x), leftChild(l), rightChild(r) {}
    };
}

namespace diguiVisit
{
    using namespace myTree;
    template <typename T>
    void preOrder(treeNode<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        std::cout << root->data << " ";
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }

    template <typename T>
    void inOrder(treeNode<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->leftChild);
        std::cout << root->data << " ";
        inOrder(root->rightChild);
    }

    template <typename T>
    void postOrder(treeNode<T> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        std::cout << root->data << " ";
    }
}


namespace stackVisit
{
    using namespace myTree;
    using namespace myStack;
    template <typename T>
    void preOrder(treeNode<T> *root)
    {
        mystack<treeNode<T> *> s;
        treeNode<T> *p = root;
        while (1)
        {
            while (p != nullptr)
            {
                std::cout << p->data << " ";
                s.push(p);
                p = p->leftChild;
            }
            if (s.empty()) {
                return;
            }
            p = s.pop();
            p = p->rightChild;
        }
    }

    template <typename T>
    void inOrder(treeNode<T> *root) {
        mystack<treeNode<T> *> s;
        treeNode<T> *p = root;
        while (1) {
            while (p) {
                s.push(p);
                p = p->leftChild;
            }
            if (s.empty()) {
                return;
            }
            p = s.pop();
            cout << p->data << " ";
            p = p->rightChild;
        }
    }

    template <typename T>
    void postOrder(treeNode<T> *root) {
        mystack<treeNode<T> *> s;
        treeNode<T> *cur = root, pre = nullptr;
        while (1) {
            while (cur) {
                s.push(cur);
                cur = cur->leftChild;
            }
            if (s.empty()) {
                return;
            }
            cur = s.top();
            if (cur->rightChild == nullptr || cur->rightChild == pre) {
                cout << cur->data << " ";
                s.pop();
                pre = cur;
                cur = nullptr;
            } else {
                cur = cur->rightChild;
            }
        }
    }

    template <typename T>
    void postOrder2(treeNode<T> *root) {
        mystack<pair<treeNode<T> *, int>> s;
        if (root) {
            s.push(make_pair(root, 0));
        }
        while (!s.empty()) {
            pair<treeNode<T> *, int> cur = s.pop();
            if (cur.second == 0) {
                s.push(make_pair(cur.first, 1));
                if (cur.first->leftChild) {
                    s.push(make_pair(cur.first->leftChild, 0));
                }
            } else if (cur.second == 1) {
                s.push(make_pair(cur.first, 2));
                if (cur.first->rightChild) {
                    s.push(make_pair(cur.first->rightChild, 0));
                }
            } else {
                cout << cur.first->data << " ";
            }
        }
    }
}
#endif
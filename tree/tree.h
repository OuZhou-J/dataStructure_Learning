#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "myStack.h"
#include "myQueue.h"

namespace myTree
{
    template <typename T>
    struct TreeNode
    {
        T data;
        TreeNode<T> *leftChild;
        TreeNode<T> *rightChild;
        TreeNode() : leftChild(nullptr), rightChild(nullptr) {}
        TreeNode(T x, TreeNode<T> *l = nullptr, TreeNode<T> *r = nullptr) : data(x), leftChild(l), rightChild(r) {}
    };
}

namespace diguiVisit
{
    using namespace myTree;
    using namespace myQueue;
    template <typename T>
    void preOrder(TreeNode<T> *root)
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
    void inOrder(TreeNode<T> *root)
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
    void postOrder(TreeNode<T> *root)
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
    void preOrder(TreeNode<T> *root)
    {
        mystack<TreeNode<T> *> s;
        TreeNode<T> *p = root;
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
    void inOrder(TreeNode<T> *root) {
        mystack<TreeNode<T> *> s;
        TreeNode<T> *p = root;
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
    void postOrder(TreeNode<T> *root) {
        mystack<TreeNode<T> *> s;
        TreeNode<T> *cur = root, pre = nullptr;
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
    void postOrder2(TreeNode<T> *root) {
        mystack<pair<TreeNode<T> *, int>> s;
        if (root) {
            s.push(make_pair(root, 0));
        }
        while (!s.empty()) {
            pair<TreeNode<T> *, int> cur = s.pop();
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

    template <typename T>
    void levelOrder(TreeNode<T> *root) {
        myQueue<TreeNode<T> *> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            TreeNode<T> *cur = q.pop();
            cout << cur->data << " ";
            if (cur->leftChild) {
                q.push(cur->leftChild);
            }
            if (cur->rightChild) {
                q.push(cur->rightChild);
            }
        }
    }
}
#endif
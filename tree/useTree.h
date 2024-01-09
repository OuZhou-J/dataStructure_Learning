#include "tree.h"
#include <iostream>
#include <vector>
#include <functional>
#define left leftChild
#define right rightChild
using TreeNode = myTree::TreeNode<int>;
using namespace std;

//先根序列和中根序列构造二叉树  https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder);

//中根序列和后根序列构造二叉树  https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder);

//中根序列和层次序列构造二叉树
TreeNode* buildTree3(vector<int>& inorder, vector<int>& levelorder);

//给定先根序列和后根序列，输出可能有多少种二叉树结构 https://www.luogu.com.cn/problem/P1229
int countTree(vector<int>& preorder, vector<int>& postorder);

namespace binarySearchTree {
    using BSTnode = myTree::TreeNode<int>;
    void print(BSTnode* root);
    BSTnode* searchDiGui(BSTnode* root, int k);
    BSTnode* searchDieDai(BSTnode* root, int k);
    void Insert(BSTnode* &root, int k);
    void remove(BSTnode* &root, int k);
}

namespace HuffmanTree {
    using info = struct info {
        char c;
        int wei;
        info(char c, int wei) : c(c), wei(wei){}

        friend ostream& operator<<(ostream& os, const info& i) {
            os << "(" << i.c << ", " << i.wei << ")";
            return os;
        }
    };
    using HuffmanNode = myTree::TreeNode<info>;
    HuffmanNode* CreateHuffmanNode(const vector<char> &chars, vector<int> freq);
    void printHuffmanTreeCode(HuffmanNode* root);
}
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
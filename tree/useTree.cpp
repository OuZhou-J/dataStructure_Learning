#include "tree.h"
#include <iostream>
#include <vector>
#include <functional>
#define left leftChild
#define right rightChild
using TreeNode = myTree::TreeNode<int>;
using namespace std;

//先根序列和中根序列构造二叉树  https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    function<TreeNode*(int, int, int, int)> build = [&](int preL, int preR, int inL, int inR) -> TreeNode* {
        if (preL > preR) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preL]);
        int k = inL;
        while (k <= inR && inorder[k] != preorder[preL]) {
            ++k;
        }
        int numLeft = k - inL;
        root->leftChild = build(preL + 1, preL + numLeft, inL, k - 1);
        root->rightChild = build(preL + numLeft + 1, preR, k + 1, inR);
        return root;
    };

    return build(0, preorder.size() - 1, 0, inorder.size() - 1);
}


//中根序列和后根序列构造二叉树  https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    function<TreeNode*(int, int, int, int)> build = [&](int inL, int inR, int postL, int postR) -> TreeNode* {
        if (inL > inR) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postR]);
        int k = inL;
        while (k <= inR && inorder[k] != postorder[postR]) {
            ++k;
        }
        int numLeft = k - inL;
        root->left = build(inL, k - 1, postL, postL + numLeft - 1);
        root->rightChild = build(k + 1, inR, postL + numLeft, postR - 1);
        return root;
    };

    return build(0, inorder.size() - 1, 0, postorder.size() - 1);
}

//中根序列和层次序列构造二叉树
TreeNode* buildTree(vector<int>& inorder, vector<int>& levelorder) {
    function<TreeNode*(int, int, int, int)> build = [&](int inL, int inR, int levelL, int levelR) -> TreeNode* {
        
    };
}
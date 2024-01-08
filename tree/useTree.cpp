#include "useTree.h"

//先根序列和中根序列构造二叉树  https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) {
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
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) {
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
TreeNode* buildTree3(vector<int>& inorder, vector<int>& levelorder) {
    function<TreeNode*(int, int, int)> build = [&](int il, int ir, int levelloc) -> TreeNode* {
        if (il > ir) {
            return nullptr;
        }
        int k = levelloc;
        int loc;
        for (; k < levelorder.size(); ++k) {
            for (loc = il; loc <= ir; ++loc) {
                if (inorder[loc] == levelorder[k]) {
                    break;
                }
            }
            if (loc <= ir) {
                break;
            }
        }
        TreeNode* root = new TreeNode(levelorder[k]);
        root->leftChild = build(il, loc - 1, k + 1);
        root->rightChild = build(loc + 1, ir, k + 1);
        return root;
    };
    return build(0, inorder.size() - 1, 0);
}


int countTree(vector<int>& preorder, vector<int>& postorder) {
    int n = preorder.size();
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (preorder[i] == postorder[j] && preorder[i + 1] == postorder[j - 1]) {
                ans *= 2;
            }
        }
    }
    return ans;
}


namespace binarySearchTree {
    using BSTnode = myTree::TreeNode<int>;

    BSTnode* searchDiGui(BSTnode* root, int k) {
        if (root == nullptr || root->data == k) {
            return root;
        }
        return root->data < k ? searchDiGui(root->right, k) : searchDiGui(root->left, k);
    }    

    BSTnode* searchDieDai(BSTnode* root, int k) {
        BSTnode* p = root;
        while (p) {
            if (p->data == k) {
                return p;
            }
            p = p->data < k ? p->right : p->left;
        }
        return nullptr;
    }

    void Insert(BSTnode* &root, int k) {
        if (!root) {
            root = new BSTnode(k);
        }
        if (root->data < k) {
            Insert(root->right, k);   
        }
        else if (root->data > k) {
            Insert(root->left, k);
        }
        else {
            return;
        }
    }


    void remove(BSTnode* &root, int k) {
        if (!root) { return; }
        else if (root->data < k) {
            remove(root->right, k);
        }
        else if (root->data > k) {
            remove(root->left, k);
        }
        else if (root->left && root->right) {
            BSTnode* tmp = root->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            root->data = tmp->data;
            remove(root->left, tmp->data);
        }
        else {
            BSTnode* tmp = root;
            root = root->right ? root->right : root->left;
            delete(tmp);
        }
    }
}


namespace HuffmanTree {
    HuffmanNode* CreateHuffmanNode(const vector<char> &chars, vector<int> freq) {
        int size = chars.size();
        vector<HuffmanNode*> house;
        for (int i = 0; i < size; ++i) {
            house.push_back(new HuffmanNode(info(chars[i], freq[i])));
        }
        sort(house.begin(), house.end(), [](HuffmanNode* a, HuffmanNode* b) -> bool {
            return a->data.wei < b->data.wei;
        });

        for (int i = 0; i < size - 1; ++i) {
            HuffmanNode *tmp1 = house[i];
            HuffmanNode *tmp2 = house[i+1];
            HuffmanNode *newnode = new HuffmanNode(info(' ', tmp1->data.wei + tmp2->data.wei));
            newnode->left = tmp1;
            newnode->right = tmp2;
            int j = i + 2;
            while (j < size && house[j]->data.wei < newnode->data.wei) {
                house[j-1] = house[j];
                j++;
            }
            house[j-1] = newnode;
        }
        return house.back();
    }
}
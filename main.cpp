#include <iostream>
#include <vector>
#include <string>
#include "useStack.h"
#include "./string/relationFunc.h"
#include "./tree/useTree.h"
using namespace std;
int main()
{
    vector<char> chars = {'a', 'b', 'l', 'i'};
    vector<int> freq = {3, 2, 1, 1};
    HuffmanTree::HuffmanNode *root = HuffmanTree::CreateHuffmanNode(chars, freq);
    diguiVisit::preOrder(root);
}
